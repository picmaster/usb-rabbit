// 13.Feb.2013
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

#include <usb_rabbit.h>

#include <stdio.h>

void print_usage(void)
{
    printf("Usage: send_file <filename>\n");
}

int main(int argc, char** argv)
{
    ur_context_t* ctx = NULL;

    if (argc != 3)
    {
        print_usage();
        return 1;
    }

    ctx = ur_context_new();
    if (NULL == ctx)
    {
        printf("ERROR: %s:%d - ur_context_new() failed!\n", __FILE__, __LINE__);
        return 1;
    }

    ur_init(ctx, "usb device id");



    ur_send_data



    ur_cleanup(ctx);
    ur_context_delete(&ctx);
    return 0;
}
