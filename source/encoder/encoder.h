/*****************************************************************************
 * Copyright (C) 2013 x265 project
 *
 * Authors: Steve Borho <steve@borho.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 *
 * This program is also available under a commercial proprietary license.
 * For more information, contact us at licensing@multicorewareinc.com.
 *****************************************************************************/

#ifndef __ENCODER__
#define __ENCODER__

#include "TLibEncoder/TEncTop.h"
#include "common.h"
#include "x265.h"
#include <vector>

namespace x265 {
// private namespace

class Encoder : public TEncTop
{
protected:
    bool InitializeGOP(x265_param_t *param);
    void determineLevelAndProfile(x265_param_t *param);

public:

    std::vector<x265_nal_t> m_nals;
    std::string             m_packetData;

    Encoder()
    {
        // preallocate these containers
        m_packetData.reserve(4096);
        m_nals.reserve(4);
    }

    virtual ~Encoder() {}

    void configure(x265_param_t *param);
};
}
#endif // ifndef __ENCODER__
