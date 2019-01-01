#ifndef OCRABSTRACTMOVERESIZEWIDGET_H
#define OCRABSTRACTMOVERESIZEWIDGET_H

/* =================================================
 * This file is part of the TTK OCR project
 * Copyright (C) 2015 - 2019 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QWidget>
#include "ocrobject.h"
#include "ocrglobaldefine.h"

/*! @brief The class of the moving resize struct.
 * @author Greedysky <greedysky@163.com>
 */
struct OCR_WIDGET_EXPORT MoveResizeStruct
{
    bool m_mouseLeftPress;
    bool m_isPressBorder;
    QPoint m_mousePos;
    QPoint m_windowPos;
    QSize m_pressedSize;
};

/*! @brief The class of the moving resize widget base.
 * @author Greedysky <greedysky@163.com>
 *         Lverson   <what951006@163.com>
 */
class OCR_WIDGET_EXPORT OCRAbstractMoveResizeWidget : public QWidget
{
    Q_OBJECT
public:
    enum Direction
    {
        Direction_No = 0,                                           /*!< no direction*/
        Direction_Left = 1,                                         /*!< left direction*/
        Direction_Top = 2,                                          /*!< top direction*/
        Direction_Right = 4,                                        /*!< right direction*/
        Direction_Bottom = 8,                                       /*!< bottom direction*/
        Direction_LeftTop = Direction_Left + Direction_Top,         /*!< left top direction*/
        Direction_LeftBottom = Direction_Left + Direction_Bottom,   /*!< left bottom direction*/
        Direction_RightTop = Direction_Right + Direction_Top,       /*!< right top direction*/
        Direction_RightBottom = Direction_Right + Direction_Bottom  /*!< right bottom direction*/
    };
    /*!
     * Object contsructor.
     */
    explicit OCRAbstractMoveResizeWidget(QWidget *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();

protected:
    /*!
     * Override the widget event.
     */
    virtual bool eventFilter(QObject *object, QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    /*!
     * Size direction detected.
     */
    void sizeDirection();
    /*!
     * Move direction to be.
     */
    void moveDirection();
    /*!
     * Get all inside widgets.
     */
    QObjectList foreachWidget(QObject *object);

    MoveResizeStruct m_struct;
    Direction m_direction;

};

#endif // OCRABSTRACTMOVERESIZEWIDGET_H
