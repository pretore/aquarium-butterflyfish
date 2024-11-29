#include <stdlib.h>
@includes
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)   (*(struct butterflyfish_stream_$t$ **) x)

#pragma mark stream_$t$ -

int butterflyfish_stream_$t$_first(
        const struct butterflyfish_stream_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->first(object, out);
}

int butterflyfish_stream_$t$_next(
        const struct butterflyfish_stream_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->next(object, item, out);
}
