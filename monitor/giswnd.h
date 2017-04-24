#ifndef GISWND_H
#define GISWND_H

#include <QWidget>
#include <QLabel>
#include <QlineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGraphicsProxyWidget>
#include <./opmap/opmapwidget.h>

using namespace mapcontrol;

class GisWnd : public QWidget
{
    Q_OBJECT
public:
    explicit GisWnd(QWidget *parent = 0);
    ~GisWnd();
	MapType::Types getMapType();
	void setMapType(MapType::Types type);
	void zoomInMap(int nScale, double lat, double lng);
	void createWp(double lat, double lng);
	void clearWp();
	void getBeginPoint();																				//测距时获取起始点
	void measureStart(QMouseEvent event);
	void measureStop();
	void clearMeasureInfo();


	bool pntOutOfChina(double lat, double lon);
	double AngleToRad(double dAngle);
	double transformLat(double x, double y);
	double transformLon(double x, double y);
	void transformPntToChinaPos(double readLat, double readLon, double &showLat, double &showLon);
	void gcjToGps84(double gcjLat, double gcjLon, double &gpsLat, double &gpsLon);
	void gps84ToGcj(double gpsLat, double gpsLon, double &gcjLat, double &gcjLon);
	double getDistanceBetweenTwoPnts(double lat1, double lng1, double lat2, double lng2);

signals:

public slots :
	void slot_mouseLeftPress(QMouseEvent event);
	void slot_mouseRightPress(QMouseEvent event);
	void slot_mouseMove(QMouseEvent event);
	void slot_RefreshPos();
	void slot_clearMeasureInfo();

private:
    OPMapWidget *m_pMapWidget;
    QHBoxLayout *m_pHLayout;
	mapcontrol::MapGraphicItem *m_pMapItem;
	double m_Dis;                                                    
	double m_disTemp;                                                
	QVector<internals::PointLatLng> m_vecPoint;                      
	QVector<QGraphicsEllipseItem *> m_vecDisEllipse;                 
	QVector<QGraphicsLineItem *> m_vecDisLine;                       
	QVector<QGraphicsProxyWidget *> m_vecDis;                        
	QVector<QGraphicsLineItem *> m_vecLine;  
	internals::PointLatLng m_beginPoint;
	QPushButton *m_pBtnClearMeasure;
	bool m_bLatLonShow;
	QLabel *m_latLonLabel;
};

#endif // GISWND_H
