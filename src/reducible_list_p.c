#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_list_p **) object)

#pragma mark stream_p -

int butterflyfish_reducible_list_p_first(
        const struct butterflyfish_reducible_list_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .collection_p
            .stream_p
            .first(object, out);
}

int butterflyfish_reducible_list_p_next(
        const struct butterflyfish_reducible_list_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .collection_p
            .stream_p
            .next(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_reducible_list_p_count(
        const struct butterflyfish_reducible_list_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .collection_p
            .count(object, out);
}

int butterflyfish_reducible_list_p_last(
        const struct butterflyfish_reducible_list_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .collection_p
            .last(object, out);
}

int butterflyfish_reducible_list_p_prev(
        const struct butterflyfish_reducible_list_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .collection_p
            .prev(object, item, out);
}

#pragma mark fixed_list_p -

int butterflyfish_reducible_list_p_get(
        const struct butterflyfish_reducible_list_p *const object,
        const uintmax_t at,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .get(object, at, out);
}

int butterflyfish_reducible_list_p_set(
        struct butterflyfish_reducible_list_p *const object,
        uintmax_t at,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .set(object, at, value);
}

int butterflyfish_reducible_list_p_set_item(
        struct butterflyfish_reducible_list_p *const object,
        void *const item,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .set_item(object, item, value);
}

int butterflyfish_reducible_list_p_at(
        const struct butterflyfish_reducible_list_p *const object,
        const void *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_p
            .at(object, item, out);
}

#pragma mark reducible_list_p -

int butterflyfish_reducible_list_p_remove(
        struct butterflyfish_reducible_list_p *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, at);
}

int butterflyfish_reducible_list_p_remove_item(
        struct butterflyfish_reducible_list_p *const object,
        const void *const item) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->remove_item(object, item);
}

int butterflyfish_reducible_list_p_remove_all_items(
        struct butterflyfish_reducible_list_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_items(object, other);
}
