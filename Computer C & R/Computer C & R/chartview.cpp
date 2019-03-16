#include "chartview.h"

ChartView::ChartView(QChart *inputChart):QChartView(inputChart) {}

void ChartView::wheelEvent(QWheelEvent *event){

    chart()->zoomReset();

    mFactor *= event->angleDelta().y() > 0 ? 0.5 : 2;

    QRectF rect = chart()->plotArea();
    QPointF c = chart()->plotArea().center();
    rect.setWidth(mFactor*rect.width());
    rect.moveCenter(c);
    chart()->zoomIn(rect);

    QChartView::wheelEvent(event);
}

void ChartView::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
    case Qt::Key_Left:
        chart()->scroll(-1110, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(1110, 0);
        break;
    //case Qt::Key_Up:
    //    chart()->scroll(0, 10);
    //    break;
    //case Qt::Key_Down:
    //    chart()->scroll(0, -10);
    //    break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}
