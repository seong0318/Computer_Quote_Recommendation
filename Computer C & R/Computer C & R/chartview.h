#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartView>

QT_CHARTS_USE_NAMESPACE

class ChartView : public QChartView{
private:
    qreal mFactor=1.0;

public:
    ChartView(QChart *inputChart);
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event);
};

#endif // CHARTVIEW_H
