// 9.Feb.2013
// picmaster@mail.bg
//
//
// Copyright (c) 2013 Nikolay Dimitrov
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "usb_rabbit.h"

//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>

// This chunk_size is recommended by the FTDI datasheet in order to achieve high enough transfer speed.
// Current speed is around 25MB/s (clarification: dummy writes with FPGA handshake on the FT232H, reception part is
// still not finished)
const unsigned int default_chunk_size = 64 * 1024;

ur_context_t* ur_context_new(void)
{
    ur_context_t* c = NULL;

    c = calloc(sizeof(), 1);
    if (NULL == c)
    {
        printf("ERROR: %s:%d - calloc() failed!\n", __FILE__, __LINE__);
    }
    else
    {
        c->chunk_size = default_chunk_size;
    }

    return c;
}

void ur_context_delete(ur_context_t** ctx)
{
    if (NULL != *ctx)
    {
        free(*ctx);
        *ctx = NULL;
    }
}

void ur_init(const ur_context_t* ctx)
{
    if (ftdi_init(ctx->fc) < 0)
    {
        printf("ERROR: %s:%d - ftdi_init() failed!\n\n", __FILE__, __LINE__);
    }

    // TODO: Add support for multiple connected FTDI devices at the same time
    if (ftdi_usb_open(ctx->fc, 0x0403, 0x6014) < 0)
    {
        printf("ERROR: %s:%d - ftdi_usb_open() failed!\n\n", __FILE__, __LINE__);
    }

    // FIXME: Clarify what's this magic number 0xFF
    if (ftdi_set_bitmode(ctx->fc, 0xFF, BITMODE_SYNCFF) < 0)
    {
        printf("ERROR: %s:%d - ftdi_set_bitmode() failed!\n\n", __FILE__, __LINE__);
    }

    if (ftdi_usb_purge_tx_buffer(ctx->fc) < 0)
    {
        printf("ERROR: %s:%d - ftdi_usb_purge_tx_buffer() failed!\n\n", __FILE__, __LINE__);
    }

    ftdi_write_data_set_chunksize(ctx->fc, ctx->chunk_size);

    // Confirm that chunk_size is set OK
    /*if (ftdi_write_data_get_chunksize(ctx, &chunk_size) < 0)
    {
        printf("ERROR: %s:%d - ftdi_write_data_get_chunksize() failed!\n\n", __FILE__, __LINE__);
    }
    printf("INFO: TX chunk_size = %d\n", chunk_size);*/
}

void ur_cleanup(void)
{
    // ...
}

void ur_send_data(const ur_context_t* ctx, const unsigned char* data, const int len)
{
    int bytes_written = 0;

    bytes_written = ftdi_write_data(ctx, data, len);
    printf("INFO: bytes_writen = %d\n", bytes_written);
}

//void ur_receive(struct ftdi_context* ctx, void* data, int len)
