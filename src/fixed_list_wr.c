#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_fixed_list_wr **) object)

#pragma mark stream_wr -

int butterflyfish_fixed_list_wr_first(
        const struct butterflyfish_fixed_list_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .stream_wr
            .first(object, out);
}

int butterflyfish_fixed_list_wr_next(
        const struct butterflyfish_fixed_list_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .stream_wr
            .next(object, item, out);
}

#pragma mark collection_wr -

int butterflyfish_fixed_list_wr_count(
        const struct butterflyfish_fixed_list_wr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .count(object, out);
}

int butterflyfish_fixed_list_wr_last(
        const struct butterflyfish_fixed_list_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .last(object, out);
}

int butterflyfish_fixed_list_wr_prev(
        const struct butterflyfish_fixed_list_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_wr
            .prev(object, item, out);
}

#pragma mark fixed_list_wr -

int butterflyfish_fixed_list_wr_get(
        const struct butterflyfish_fixed_list_wr *const object,
        const uintmax_t at,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, at, out);
}

int butterflyfish_fixed_list_wr_set(
        struct butterflyfish_fixed_list_wr *object,
        uintmax_t at,
        const struct triggerfish_weak *value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set(object, at, value);
}

int butterflyfish_fixed_list_wr_at(
        const struct butterflyfish_fixed_list_wr *const object,
        const struct triggerfish_weak *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->at(object, item, out);
}
