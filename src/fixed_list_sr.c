#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_fixed_list_sr **) object)

#pragma mark stream_sr -

int butterflyfish_fixed_list_sr_first(
        const struct butterflyfish_fixed_list_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .first(object, out);
}

int butterflyfish_fixed_list_sr_next(
        const struct butterflyfish_fixed_list_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .next(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_fixed_list_sr_count(
        const struct butterflyfish_fixed_list_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .count(object, out);
}

int butterflyfish_fixed_list_sr_last(
        const struct butterflyfish_fixed_list_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .last(object, out);
}

int butterflyfish_fixed_list_sr_prev(
        const struct butterflyfish_fixed_list_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .prev(object, item, out);
}

#pragma mark fixed_list_sr -

int butterflyfish_fixed_list_sr_as_stream(
        const struct butterflyfish_fixed_list_sr *const object,
        const struct butterflyfish_stream_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_sr *)
            &object->collection_sr.stream_sr;
    return 0;
}

int butterflyfish_fixed_list_sr_as_collection(
        const struct butterflyfish_fixed_list_sr *const object,
        const struct butterflyfish_collection_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_sr *) &object->collection_sr;
    return 0;
}

int butterflyfish_fixed_list_sr_get(
        const struct butterflyfish_fixed_list_sr *const object,
        const uintmax_t at,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, at, out);
}

int butterflyfish_fixed_list_sr_set(
        struct butterflyfish_fixed_list_sr *const object,
        uintmax_t at,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set(object, at, value);
}

int butterflyfish_fixed_list_sr_set_item(
        struct butterflyfish_fixed_list_sr *const object,
        struct triggerfish_strong *const item,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set_item(object, item, value);
}

int butterflyfish_fixed_list_sr_at(
        const struct butterflyfish_fixed_list_sr *const object,
        const struct triggerfish_strong *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->at(object, item, out);
}
