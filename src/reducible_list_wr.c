#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_list_wr **) object)

#pragma mark stream_wr -

int butterflyfish_reducible_list_wr_first(
        const struct butterflyfish_reducible_list_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .collection_wr
            .stream_wr
            .first(object, out);
}

int butterflyfish_reducible_list_wr_next(
        const struct butterflyfish_reducible_list_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .collection_wr
            .stream_wr
            .next(object, item, out);
}

#pragma mark collection_wr -

int butterflyfish_reducible_list_wr_count(
        const struct butterflyfish_reducible_list_wr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .collection_wr
            .count(object, out);
}

int butterflyfish_reducible_list_wr_last(
        const struct butterflyfish_reducible_list_wr *const object,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .collection_wr
            .last(object, out);
}

int butterflyfish_reducible_list_wr_prev(
        const struct butterflyfish_reducible_list_wr *const object,
        const struct triggerfish_weak *const item,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .collection_wr
            .prev(object, item, out);
}

#pragma mark fixed_list_wr -

int butterflyfish_reducible_list_wr_get(
        const struct butterflyfish_reducible_list_wr *const object,
        const uintmax_t at,
        const struct triggerfish_weak **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .get(object, at, out);
}

int butterflyfish_reducible_list_wr_set(
        struct butterflyfish_reducible_list_wr *object,
        uintmax_t at,
        const struct triggerfish_weak *value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .set(object, at, value);
}

int butterflyfish_reducible_list_wr_at(
        const struct butterflyfish_reducible_list_wr *const object,
        const struct triggerfish_weak *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_wr
            .at(object, item, out);
}

#pragma mark reducible_list_wr -

int butterflyfish_reducible_list_wr_remove(
        struct butterflyfish_reducible_list_wr *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, at);
}

int butterflyfish_reducible_list_wr_remove_item(
        struct butterflyfish_reducible_list_wr *const object,
        const struct triggerfish_weak *const item) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->remove_item(object, item);
}

int butterflyfish_reducible_list_wr_remove_all_items(
        struct butterflyfish_reducible_list_wr *const object,
        const struct butterflyfish_stream_wr *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_WR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_items(object, other);
}
