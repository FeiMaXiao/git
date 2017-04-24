#include "giswnd.h"

const double ee = 0.00669342162296594323;
const double a = 6378245.0;
const double EARTH_RADIUS = 6378.137;		//地球半径 KM

GisWnd::GisWnd(QWidget *parent) : QWidget(parent)
  , m_pHLayout(0)
  , m_pMapWidget(0)
  , m_pBtnClearMeasure(0)
  , m_latLonLabel(0)
  , m_bLatLonShow(false)
  , m_Dis(0)
  , m_disTemp(0)
{
    m_pHLayout = new QHBoxLayout();
    m_pHLayout->setContentsMargins(0, 0, 0, 0);
    m_pMapWidget = new OPMapWidget();
    m_pMapWidget->SetMapType(MapType::GoogleHybridChina);
    m_pMapWidget->setRenderHint(QPainter::Antialiasing);                         //抗锯齿
    m_pMapWidget->setCacheMode(QGraphicsView::CacheBackground);                  //缓冲背景，加速渲染
    m_pMapWidget->SetShowHome(false);

	m_pMapItem = m_pMapWidget->getMapItem();
    m_pMapWidget->SetZoom(m_pMapWidget->ZoomTotal() + 1.00);

	m_latLonLabel = new QLabel(m_pMapWidget);
	m_latLonLabel->setFixedSize(200, 15);
	m_latLonLabel->setVisible(false);
	m_latLonLabel->setStyleSheet("QLabel{background:transparent;color:red}");

	m_pBtnClearMeasure = new QPushButton(m_pMapWidget);
	m_pBtnClearMeasure->setFixedSize(14, 13);
	m_pBtnClearMeasure->setStyleSheet("QPushButton{border-image:url(./image/delete.png);}");
	m_pBtnClearMeasure->setVisible(false);

    m_pHLayout->addWidget(m_pMapWidget);

    this->setLayout(m_pHLayout);

	connect(m_pMapWidget, SIGNAL(sig_mouseLeftPress(QMouseEvent)), this, SLOT(slot_mouseLeftPress(QMouseEvent)));
	connect(m_pMapWidget, SIGNAL(sig_mouseRightPress(QMouseEvent)), this, SLOT(slot_mouseRightPress(QMouseEvent)));
	connect(m_pMapWidget, SIGNAL(sig_mouseMove(QMouseEvent)), this, SLOT(slot_mouseMove(QMouseEvent)));
	connect(m_pBtnClearMeasure, SIGNAL(clicked()), this, SLOT(slot_clearMeasureInfo()));
	connect(m_pMapItem, SIGNAL(childRefreshPosition()), this, SLOT(slot_RefreshPos()));
	
}

GisWnd::~GisWnd()
{
	delete m_latLonLabel;
	delete m_pBtnClearMeasure;
    delete m_pMapWidget;
    delete m_pHLayout;
}

MapType::Types GisWnd::getMapType()
{
	return m_pMapWidget->GetMapType();
}

void GisWnd::setMapType(MapType::Types type)
{
	m_pMapWidget->SetMapType(type);
}

void GisWnd::zoomInMap(int nScale, double lat, double lng)
{
	internals::MouseWheelZoomType::Types zoom_type = m_pMapWidget->GetMouseWheelZoomType();
	m_pMapWidget->SetMouseWheelZoomType(internals::MouseWheelZoomType::ViewCenter);
	m_pMapWidget->SetZoom(nScale);
	m_pMapWidget->SetMouseWheelZoomType(zoom_type);
	m_pMapWidget->SetCurrentPosition(internals::PointLatLng(lat, lng));
}

void GisWnd::createWp(double lat, double lng)
{
	double templat = lat;
	double templng = lng;
	gps84ToGcj(lat, lng, templat, templng);
	m_pMapWidget->WPCreate(internals::PointLatLng(templat, templng), 0, "");

	zoomInMap(15, templat, templng);
}

void GisWnd::clearWp()
{
	m_pMapWidget->WPDeleteAll();
}

bool GisWnd::pntOutOfChina(double lat, double lon)
{
	if (lon < 72.004 || lon > 137.8347)
	{
		return true;					//不在中国境内
	}
	if (lat < 0.8293 || lat > 55.8271)
	{
		return true;				   //不在中国境内
	}
	return false;
}

double GisWnd::AngleToRad(double dAngle)
{
	return dAngle * M_PI / 180.0;
}

double GisWnd::transformLat(double x, double y)
{
	double ret = -100.0 + 2.0 * x + 3.0 * y + 0.2 * y * y + 0.1 * x * y + 0.2 * sqrt(abs(x));
	ret += (20.0 * sin(6.0 * x * M_PI) + 20.0 * sin(2.0 * x * M_PI)) * 2.0 / 3.0;
	ret += (20.0 * sin(y * M_PI) + 40.0 * sin(y / 3.0 * M_PI)) * 2.0 / 3.0;
	ret += (160.0 * sin(y / 12.0 * M_PI) + 320 * sin(y * M_PI / 30.0)) * 2.0 / 3.0;
	return ret;
}

double GisWnd::transformLon(double x, double y)
{
	double ret = 300.0 + x + 2.0 * y + 0.1 * x * x + 0.1 * x * y + 0.1 * sqrt(abs(x));
	ret += (20.0 * sin(6.0 * x * M_PI) + 20.0 * sin(2.0 * x * M_PI)) * 2.0 / 3.0;
	ret += (20.0 * sin(x * M_PI) + 40.0 * sin(x / 3.0 * M_PI)) * 2.0 / 3.0;
	ret += (150.0 * sin(x / 12.0 * M_PI) + 300.0 * sin(x / 30.0 * M_PI)) * 2.0 / 3.0;
	return ret;
}

void GisWnd::transformPntToChinaPos(double readLat, double readLon, double &showLat, double &showLon)
{
	if (pntOutOfChina(readLat, readLon))		//不在中国境内
	{
		showLat = readLat;
		showLon = readLon;
	}
	else
	{
		double dLat = transformLat(readLon - 105.0, readLat - 35.0);
		double dLon = transformLon(readLon - 105.0, readLat - 35.0);
		double radLat = readLat / 180.0 * M_PI;
		double magic = sin(radLat);
		magic = 1 - ee * magic * magic;
		double sqrtMagic = sqrt(magic);
		dLat = (dLat * 180.0) / ((a * (1 - ee)) / (magic * sqrtMagic) * M_PI);
		dLon = (dLon * 180.0) / (a / sqrtMagic * cos(radLat) * M_PI);
		showLat = readLat + dLat;
		showLon = readLon + dLon;
	}
}

void GisWnd::gcjToGps84(double gcjLat, double gcjLon, double &gpsLat, double &gpsLon)
{
	double outLat, outLon;
	transformPntToChinaPos(gcjLat, gcjLon, outLat, outLon);
	gpsLat = gcjLat * 2 - outLat;
	gpsLon = gcjLon * 2 - outLon;
}

void GisWnd::gps84ToGcj(double gpsLat, double gpsLon, double &gcjLat, double &gcjLon)
{
	if (pntOutOfChina(gpsLat, gpsLon))
	{
		return;
	}

	double dLat = transformLat(gpsLon - 105.0, gpsLat - 35.0);
	double dLon = transformLon(gpsLon - 105.0, gpsLat - 35.0);
	double radLat = gpsLat / 180.0 * M_PI;
	double magic = sin(radLat);
	magic = 1 - ee * magic * magic;
	double sqrtMagic = sqrt(magic);
	dLat = (dLat * 180.0) / ((a * (1 - ee)) / (magic * sqrtMagic) * M_PI);
	dLon = (dLon * 180.0) / (a / sqrtMagic * std::cos(radLat) * M_PI);
	gcjLat = gpsLat + dLat;
	gcjLon = gpsLon + dLon;
}

double GisWnd::getDistanceBetweenTwoPnts(double lat1, double lng1, double lat2, double lng2)
{
	double radLat1 = AngleToRad(lat1);
	double radLat2 = AngleToRad(lat2);
	double a = radLat1 - radLat2;
	double b = AngleToRad(lng1) - AngleToRad(lng2);

	double s = 2 * qAsin(qSqrt(qPow(qSin(a / 2), 2) + qCos(radLat1) * qCos(radLat2) * qPow(qSin(b / 2), 2)));
	s = s * EARTH_RADIUS;
	return s;
}

void GisWnd::getBeginPoint()
{
	QFont font("微软雅黑", 10);

	QPen pen;
	QBrush brush(QColor(255, 255, 255));
	pen.setColor(Qt::red);
	pen.setWidth(3);

	QPen penEllipse;
	penEllipse.setColor(Qt::red);
	penEllipse.setWidth(2);

	double lat = m_pMapWidget->currentMousePosition().Lat();
	double lon = m_pMapWidget->currentMousePosition().Lng();
	m_vecPoint.append(internals::PointLatLng(lat, lon));
	double x1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 1)).X();
	double y1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 1)).Y();
	QRectF rect(x1 - 6, y1 - 6, 12, 12);
	m_vecDisEllipse.append(m_pMapWidget->GetScence()->addEllipse(rect, penEllipse, brush));

	if (!m_bLatLonShow)
	{
		m_bLatLonShow = true;
		m_latLonLabel->setVisible(m_bLatLonShow);
		m_beginPoint = m_vecPoint.at(m_vecPoint.size() - 1);
	}

	if (m_vecPoint.size() > 1)
	{
		double x1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 2)).X();
		double y1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 2)).Y();
		double x2 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 1)).X();
		double y2 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 1)).Y();
		m_vecDisLine.append(m_pMapWidget->GetScence()->addLine(QLineF(x1, y1, x2, y2), pen));
		m_beginPoint = m_vecPoint.at(m_vecPoint.size() - 1);

		QLineEdit *pline = new QLineEdit;
		pline->setEnabled(false);
		pline->setStyleSheet("QLineEdit{background-color:rgba(255,0,0,0);color:white;font:10pt;}");
		pline->setFont(font);
		pline->setAlignment(Qt::AlignCenter);
		m_Dis = m_Dis + m_disTemp;
		QString s = QString::number(m_Dis, 'f', 1) + "m";
		pline->setText(s);
		pline->setFixedWidth(s.length() * font.pointSize() - 5);
		m_vecDis.append(m_pMapWidget->GetScence()->addWidget(pline));
		m_vecDis.at(m_vecDis.size() - 1)->setPos(x2 - (pline->width() / 2), y2 - 28);
		m_vecDis.at(m_vecDis.size() - 1)->setZValue(1);
	}
}

void GisWnd::measureStart(QMouseEvent event)
{
	if (m_bLatLonShow)
	{
		double x = m_pMapItem->FromLatLngToLocal(m_pMapWidget->GetFromLocalToLatLng(QPointF(event.x(), event.y()))).X();
		double y = m_pMapItem->FromLatLngToLocal(m_pMapWidget->GetFromLocalToLatLng(QPointF(event.x(), event.y()))).Y();

		double lat = m_pMapWidget->currentMousePosition().Lat();
		double lon = m_pMapWidget->currentMousePosition().Lng();
		m_disTemp = getDistanceBetweenTwoPnts(m_beginPoint.Lat(), m_beginPoint.Lng(), lat, lon) * 1000;		//米
		QString slen = QString::number(m_disTemp, 'f', 1) + "m";
		m_latLonLabel->setText(slen);
		m_latLonLabel->move(x + 15, y);

		QPen pen;
		QBrush brush;
		pen.setColor(Qt::red);
		pen.setWidth(3);
		if (m_vecLine.size() == 1)
		{
			delete m_vecLine[m_vecLine.size() - 1];
			m_vecLine.pop_back();
		}

		double x1 = m_pMapItem->FromLatLngToLocal(m_beginPoint).X();
		double y1 = m_pMapItem->FromLatLngToLocal(m_beginPoint).Y();
		double x2 = m_pMapItem->FromLatLngToLocal(internals::PointLatLng(lat, lon)).X();
		double y2 = m_pMapItem->FromLatLngToLocal(internals::PointLatLng(lat, lon)).Y();
		m_vecLine.append(m_pMapWidget->GetScence()->addLine(QLineF(x1, y1, x2, y2), pen));
	}
}

void GisWnd::measureStop()
{
	if (!m_vecDisEllipse.isEmpty())
	{
		if (m_vecPoint.isEmpty())
		{
			return;
		}

		if (m_vecLine.isEmpty())
		{
			return;
		}

		m_bLatLonShow = false;
		m_latLonLabel->setVisible(m_bLatLonShow);
		double x1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 1)).X();
		double y1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(m_vecPoint.size() - 1)).Y();
		m_pBtnClearMeasure->move(x1 + 6, y1 + 6);
		delete m_vecLine.at(m_vecLine.size() - 1);
		m_vecLine.removeAt(m_vecLine.size() - 1);
		m_pBtnClearMeasure->setVisible(true);
	}
}

void GisWnd::clearMeasureInfo()
{
	if (m_pBtnClearMeasure)
	{
		m_pBtnClearMeasure->setVisible(false);
	}

	for (int i = m_vecDisEllipse.size() - 1; i >= 0; i--)
	{
		delete m_vecDisEllipse.at(i);
		m_vecDisEllipse.pop_back();
	}

	for (int i = m_vecDisLine.size() - 1; i >= 0; i--)
	{
		delete m_vecDisLine.at(i);
		m_vecDisLine.pop_back();
	}

	for (int i = m_vecDis.size() - 1; i >= 0; i--)
	{
		delete m_vecDis.at(i);
		m_vecDis.pop_back();
	}

	m_vecPoint.clear();
	m_latLonLabel->clear();
	m_Dis = 0;
}

void GisWnd::slot_mouseLeftPress(QMouseEvent event)
{
	measureStop();
}

void GisWnd::slot_mouseRightPress(QMouseEvent event)
{
	getBeginPoint();
}

void GisWnd::slot_mouseMove(QMouseEvent event)
{
	measureStart(event);
}

void GisWnd::slot_RefreshPos()
{
	double x1, y1, x2, y2;
	for (int i = 0; i < m_vecPoint.size(); i++)
	{
		x1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(i)).X();
		y1 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(i)).Y();
		m_vecDisEllipse.at(i)->setRect(QRectF(x1 - 6, y1 - 6, 12, 12));
		m_pBtnClearMeasure->move(x1 + 6, y1 + 6);
		if (i > 0)
		{
			x2 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(i - 1)).X();
			y2 = m_pMapItem->FromLatLngToLocal(m_vecPoint.at(i - 1)).Y();
			m_vecDisLine.at(i - 1)->setLine(x2, y2, x1, y1);
			m_vecDis.at(i - 1)->setPos(x1 - m_vecDis.at(i - 1)->widget()->width() / 2, y1 - 28);
		}
	}
}

void GisWnd::slot_clearMeasureInfo()
{
	clearMeasureInfo();
}

