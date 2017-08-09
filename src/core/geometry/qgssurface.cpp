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
#include "qgspoint.h"

QgsRectangle QgsSurface::boundingBox() const
{
  if ( mBoundingBox.isNull() )
  {
    mBoundingBox = calculateBoundingBox();
  }
  return mBoundingBox;
}

QgsAbstractGeometry *QgsSurface::asGridified( double /* hSpacing */, double /* vSpacing */, double /* dSpacing */, double /* mSpacing */, double /* tolerance */, SegmentationToleranceType /* toleranceType */ ) const
{
  // This should never be called. Required from SIP.
  return nullptr;
}

void QgsSurface::clearCache() const
{
  mBoundingBox = QgsRectangle();
  mCoordinateSequence.clear();
  QgsAbstractGeometry::clearCache();
}
