/**********************************************************************
 *
 *    FILE:            DrawElementsUByte.cpp
 *
 *    DESCRIPTION:    Read/Write osg::DrawElementsUByte in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerated
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 20.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "DrawElementsUByte.h"
#include "PrimitiveSet.h"

using namespace ive;

void DrawElementsUByte::write(DataOutputStream* out){
    // Write DrawElementsUByte's identification.
    out->writeInt(IVEDRAWELEMENTSUBYTE);

    // If the osg class is inherited by any other class we should also write this to file.
    osg::PrimitiveSet*  prim = dynamic_cast<osg::PrimitiveSet*>(this);
    if(prim){
        ((ive::PrimitiveSet*)(prim))->write(out);
    }
    else
        throw Exception("DrawElementsUByte::write(): Could not cast this osg::DrawElementsUByte to an osg::PrimitiveSet.");
    // Write DrawElementsUByte's properties.

    // Write array length and its elements.
    out->writeInt(size());
    out->writeCharArray((const char*)&front(), size() * CHARSIZE);
}

void DrawElementsUByte::read(DataInputStream* in){
    // Read DrawElementsUByte's identification.
    int id = in->peekInt();
    if(id == IVEDRAWELEMENTSUBYTE){
        // Code to read DrawElementsUByte's properties.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::PrimitiveSet*  prim = dynamic_cast<osg::PrimitiveSet*>(this);
        if(prim){
            ((ive::PrimitiveSet*)(prim))->read(in);
        }
        else
            throw Exception("DrawElementsUByte::read(): Could not cast this osg::DrawElementsUByte to an osg::PrimtiveSet.");

        // Read array length and its elements.
        int size = in->readInt();
        resize(size);
        in->readCharArray((char*)&front(), size * CHARSIZE);
    }
    else{
        throw Exception("DrawElementsUByte::read(): Expected DrawElementsUByte identification.");
    }
}
