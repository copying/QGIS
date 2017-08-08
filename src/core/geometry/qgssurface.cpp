/***************************************************************************
                         qgssurface.cpp
                         ---------------------
    begin                : August 2017
    copyright            : (C) 2017 by Martí Angelats i Ribera
    email                : marti.angelats at psig dot cat
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgssurface.h"
#include "qgspoint.h" // Without this header the compilation fails. Here's the explanation:
                      //   QgsCoordinateSequence is actually QList< QList< QList< QgsPoint > > >.
                      //   When you use mCoordinateSequence.clear(), you may be destroying a QList.
                      //   This makes a chain reaction until it reaches QgsPoint, which must be fully
                      //   qualified but is not (until adding this header it's forward declared).
                      //   PS: I don't even know how, but I undertood the error quite fast.

QgsRectangle QgsSurface::boundingBox() const
{
  if ( mBoundingBox.isNull() )
  {
    mBoundingBox = calculateBoundingBox();
  }
  return mBoundingBox;
}

void QgsSurface::clearCache() const
{
  mBoundingBox = QgsRectangle();
  mCoordinateSequence.clear();
  QgsAbstractGeometry::clearCache();
}
