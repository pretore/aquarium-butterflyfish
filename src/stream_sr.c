#include <stdlib.h>
#include <sea-turtle.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stream_sr **) object)

#pragma mark stream_sr -

int butterflyfish_stream_sr_first(
        const struct butterflyfish_stream_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->first(object, out);
}

int butterflyfish_stream_sr_next(
        const struct butterflyfish_stream_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->next(object, item, out);
}
