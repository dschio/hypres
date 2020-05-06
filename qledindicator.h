/***************************************************************************
 *   Copyright (C) 2010 by Tn                                              *
 *   thenobody@poczta.fm                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef QLEDINDICATOR_H
#define QLEDINDICATOR_H

#include <QAbstractButton>
#include <QResizeEvent>
#include <QColor>
#include <QTimer>
#include <QDebug>

#define LED_GREEN_1   QColor(0,245, 0)
#define LED_GREEN_2   QColor(0,192, 0)
#define LED_RED_1     QColor(245, 0, 0)
#define LED_RED_2     QColor(192, 0, 0)
#define LED_OFF_1     QColor(5,0,0)
#define LED_OFF_2     QColor(0,0,0)

class QLedIndicator : public QWidget //QAbstractButton
{
    Q_PROPERTY(QColor onColor1      WRITE setOnColor1     READ getOnColor1   );
    Q_PROPERTY(QColor onColor2      WRITE setOnColor2     READ getOnColor2   );
//    Q_PROPERTY(QColor offColor1     WRITE setOffColor1    READ getOffColor1  );
//    Q_PROPERTY(QColor offColor2     WRITE setOffColor2    READ getOffColor2  );
    Q_OBJECT
    public:
        QLedIndicator(QWidget *parent);

        void setOnColor1(QColor c)  { onColor1  = c;    }
        void setOnColor2(QColor c)  { onColor2  = c;    }

        //void setOffColor2(QColor c) { offColor2 = c;    }
        //void setOffColor1(QColor c) { offColor1 = c;    }

        QColor getOnColor1(void)    { return onColor1;  }
        QColor getOnColor2(void)    { return onColor2;  }

        //QColor getOffColor1(void)   { return offColor1; }
        //QColor getOffColor2(void)   { return offColor2; }

        void SetRed()               { setOnColor1(LED_RED_1);   setOnColor2(LED_RED_2); }
        void SetGreen()             { setOnColor1(LED_GREEN_1); setOnColor2(LED_GREEN_2); }
        void SetOff()               { setOnColor1(LED_OFF_1);   setOnColor2(LED_OFF_2); }
        void FlashGreen();


    protected:
        virtual void paintEvent (QPaintEvent *event);
        virtual void resizeEvent(QResizeEvent *event);

private slots:
        void flashTimer();

    private:
        static const qreal scaledSize;  /* init in cpp */
        QColor  onColor1, offColor1;
        QColor  onColor2, offColor2;
        QPixmap ledBuffer;
};

#endif // QLEDINDICATOR_H
