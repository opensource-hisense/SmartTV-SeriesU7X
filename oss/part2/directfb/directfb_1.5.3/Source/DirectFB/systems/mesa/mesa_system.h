/*
   (c) Copyright 2001-2009  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Hundt <andi@fischlustig.de>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef __MESA_MESA_H__
#define __MESA_MESA_H__


#define EGL_EGLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <GL/glext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <drm.h>
#include <xf86drmMode.h>


#include <fusion/shmalloc.h>

#include <core/surface_pool.h>

#include <core/layers.h>
#include <core/screens.h>

#include "vt.h"

extern const SurfacePoolFuncs mesaSurfacePoolFuncs;

extern const ScreenFuncs       *mesaScreenFuncs;
extern const DisplayLayerFuncs *mesaLayerFuncs;


typedef struct {
     FusionSHMPoolShared *shmpool;

     CoreSurfacePool     *pool;
} MesaDataShared;

typedef struct {
     MesaDataShared      *shared;

     CoreDFB             *core;
     CoreScreen          *screen;
     CoreLayer           *layer;

     int                  fd;      /* DRM file descriptor */
     EGLDisplay           dpy;
     EGLContext           ctx;


     drmModeConnector    *connector;
     drmModeEncoder      *encoder;
     drmModeModeInfo      mode;
     
     VirtualTerminal     *vt;
} MesaData;


#endif

