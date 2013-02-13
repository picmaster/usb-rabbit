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

#ifndef USB_RABBIT_H
#define USB_RABBIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ftdi.h>

typedef struct ur_context_s
{
    struct ftdi_context* fc;
    unsigned int chunk_size;
} ur_context_t;

ur_context_t* ur_context_new(void);
void ur_context_delete(ur_context_t** ctx);

void ur_init(const ur_context_t* ctx);
void ur_cleanup(const ur_context_t* ctx);

void ur_send_data(const ur_context_t* ctx, const unsigned char* data, const int len);
//void ur_receive(struct ftdi_context* ctx, void* data, int len);

#ifdef __cplusplus
}
#endif

#endif // USB_RABBIT_H
