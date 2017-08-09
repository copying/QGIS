/***************************************************************************
                         qgssurface.h
                         --------------
    begin                : September 2014
    copyright            : (C) 2014 by Marco Hugentobler
    email                : marco at sourcepole dot ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSSURFACEV2_H
#define QGSSURFACEV2_H

#include "qgis_core.h"
#include "qgis.h"
#include "qgsabstractgeometry.h"
#include "qgsrectangle.h"

class QgsPolygonV2;

/** \ingroup core
 * \class QgsSurface
 */
class CORE_EXPORT QgsSurface: public QgsAbstractGeometry
{
  public:

    /**
     * Get a polygon representation of this surface.
     * Ownership is transferred to the caller.
     */
    virtual QgsPolygonV2 *surfaceToPolygon() const = 0 SIP_FACTORY;

    /** Returns the minimal bounding box for the geometry
     */
    virtual QgsRectangle boundingBox() const override;

    // TODO Copy documentation from QgsAbstractGeometry
    virtual QgsAbstractGeometry *asGridified( double hSpacing, double vSpacing, double dSpacing = 0, double mSpacing = 0, double tolerance = M_PI_2 / 90, SegmentationToleranceType toleranceType = MaximumAngle ) const override SIP_FACTORY;

  protected:

    virtual void clearCache() const override;

    mutable QgsCoordinateSequence mCoordinateSequence;
    mutable QgsRectangle mBoundingBox;
};

#endif // QGSSURFACEV2_H
