#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include "core/os_def.h"
#include "logic/bevtree.h"

#include "test.h"

typedef struct input_t {
    int32_t ratio;
} input_t;

int32_t
condition_300_cb(void* input) {
    input_t* i = (input_t*)(input);
    if (i->ratio < 50)
        return BVT_SUCCESS;
    return BVT_ERROR;
}
int32_t
condition_301_cb(void* input) {
    input_t* i = (input_t*)(input);
    if (i->ratio >= 50)
        return BVT_SUCCESS;
    return BVT_ERROR;
}

int32_t
action_400_cb(void* input) {
    return BVT_SUCCESS;
}
int32_t
action_401_cb(void* input) {
    return BVT_SUCCESS;
}
int32_t
action_402_cb(void* input) {
    return BVT_SUCCESS;
}
int32_t
action_403_cb(void* input) {
    return BVT_SUCCESS;
}
int32_t
action_404_cb(void* input) {
    return BVT_SUCCESS;
}

int
test_bevtree() {
	int32_t ret = -1;
	int32_t loop = 0;
	srand((uint32_t)time(NULL));
    input_t i;
    struct bvt_t* bvt = bvt_load_gliffy(BEV_FILE);
    if (!bvt) {
        printf("bvt init fail\n");
        return -1;
    }
    bvt_debug(bvt);

    ret = bvt_register_callback(bvt, action_400_cb, 400);
    assert(ret == BVT_SUCCESS);
    ret = bvt_register_callback(bvt, action_401_cb, 401);
    assert(ret == BVT_SUCCESS);
    ret = bvt_register_callback(bvt, action_402_cb, 402);
    assert(ret == BVT_SUCCESS);
    ret = bvt_register_callback(bvt, action_403_cb, 403);
    assert(ret == BVT_SUCCESS);
    ret = bvt_register_callback(bvt, action_404_cb, 404);
    assert(ret == BVT_SUCCESS);
    ret = bvt_register_callback(bvt, condition_300_cb, 300);
    assert(ret == BVT_SUCCESS);
    ret = bvt_register_callback(bvt, condition_301_cb, 301);
    assert(ret == BVT_SUCCESS);

    while (loop ++ < BEV_LOOP) {
        i.ratio = rand() % 100;
        ret = bvt_run(bvt, (void*)&i);
        assert(BVT_SUCCESS == ret);
        printf("============\n\n");
        SLEEP(100);
    }

    bvt_release(bvt);
    return 0;
}
