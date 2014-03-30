#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "test_coroutine.inl"
#include "test_util.inl"
#include "test_conhash.inl"
#include "test_fsm.inl"
#include "test_bitset.inl"
#include "test_heap.inl"
#include "test_rbtree.inl"
#include "test_rbuffer.inl"

int
main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: ./test <base64>\n"
            "\t<wscode>\n"
            "\t<random>\n"
            "\t<shuffle>\n"
            "\t<unicode>\n"
            "\t<conhash>\n"
#ifdef OS_LINUX
            "\t<coroutine>\n"
#endif
            "\t<fsm>\n"
            "\t<bitset>\n"
            "\t<heap>\n"
            "\t<rbtree>\n"
            "\t<rbuffer>\n");
        return 0;
    }

    if (0 == strcmp(argv[1], "base64")) {
        test_base64();
    } else if (0 == strcmp(argv[1], "wscode")) {
        test_wscode();
    } else if (0 == strcmp(argv[1], "random")) {
        test_random();
    } else if (0 == strcmp(argv[1], "shuffle")) {
        test_shuffle();
    } else if (0 == strcmp(argv[1], "unicode")) {
        test_unicode();
    } else if (0 == strcmp(argv[1], "conhash")) {
        test_conhash();
    }
#ifdef OS_LINUX
    else if (0 == strcmp(argv[1], "coroutine")) {
        test_coroutine();
    }
#endif
    else if (0 == strcmp(argv[1], "fsm")) {
        test_fsm();
    } else if (0 == strcmp(argv[1], "bitset")) {
        test_bitset();
    } else if (0 == strcmp(argv[1], "heap")) {
        test_heap();
    } else if (0 == strcmp(argv[1], "rbtree")) {
        test_rbtree();
    } else if (0 == strcmp(argv[1], "rbuffer")) {
        test_rbuffer();
    }
    return 0;
}

