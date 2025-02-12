/*
 * Copyright 2021 Rémi Bernon for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINEBUS_UNIXLIB_H
#define __WINEBUS_UNIXLIB_H

#include <stdarg.h>

#include <windef.h>
#include <winbase.h>
#include <winternl.h>
#include <ddk/wdm.h>
#include <hidusage.h>

#include "wine/list.h"
#include "wine/unixlib.h"

struct sdl_bus_options
{
    BOOL map_controllers;
};

struct udev_bus_options
{
    BOOL disable_hidraw;
    BOOL disable_input;
};

struct iohid_bus_options
{
};

struct unix_device;

enum bus_event_type
{
    BUS_EVENT_TYPE_NONE,
    BUS_EVENT_TYPE_DEVICE_REMOVED,
};

struct bus_event
{
    enum bus_event_type type;
    struct list entry;

    union
    {
        struct
        {
            const WCHAR *bus_id;
            void *context;
        } device_removed;
    };
};

struct device_create_params
{
    struct unix_device *device;
};

enum unix_funcs
{
    sdl_init,
    sdl_wait,
    sdl_stop,
    udev_init,
    udev_wait,
    udev_stop,
    iohid_init,
    iohid_wait,
    iohid_stop,
    mouse_create,
    keyboard_create,
};

extern const unixlib_entry_t __wine_unix_call_funcs[] DECLSPEC_HIDDEN;

#endif /* __WINEBUS_UNIXLIB_H */
