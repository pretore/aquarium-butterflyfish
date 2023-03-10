#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_list_ni **) object)

#pragma mark stream_ni -

int butterflyfish_list_ni_first(
        const struct butterflyfish_list_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .collection_ni
            .stream_ni
            .first(object, out);
}

int butterflyfish_list_ni_next(
        const struct butterflyfish_list_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .collection_ni
            .stream_ni
            .next(object, item, out);
}

#pragma mark collection_ni -

int butterflyfish_list_ni_count(
        const struct butterflyfish_list_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .collection_ni
            .count(object, out);
}

int butterflyfish_list_ni_last(
        const struct butterflyfish_list_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .collection_ni
            .last(object, out);
}

int butterflyfish_list_ni_prev(
        const struct butterflyfish_list_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .collection_ni
            .prev(object, item, out);
}

#pragma mark fixed_list_ni -

int butterflyfish_list_ni_get(
        const struct butterflyfish_list_ni *const object,
        const uintmax_t at,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .get(object, at, out);
}

int butterflyfish_list_ni_set(
        struct butterflyfish_list_ni *object,
        uintmax_t at,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .set(object, at, value);
}

int butterflyfish_list_ni_at(
        const struct butterflyfish_list_ni *const object,
        const uintmax_t *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .fixed_list_ni
            .at(object, item, out);
}

#pragma mark reducible_list_ni -

int butterflyfish_list_ni_remove(
        struct butterflyfish_list_ni *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .remove(object, at);
}

int butterflyfish_list_ni_remove_item(
        struct butterflyfish_list_ni *const object,
        const uintmax_t *const item) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .remove_item(object, item);
}

int butterflyfish_list_ni_remove_all_items(
        struct butterflyfish_list_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->reducible_list_ni
            .remove_all_items(object, other);
}

#pragma mark list_ni -

int butterflyfish_list_ni_add(
        struct butterflyfish_list_ni *const object,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_list_ni_add_all(
        struct butterflyfish_list_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_list_ni_insert(
        struct butterflyfish_list_ni *const object,
        const uintmax_t at,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->insert(object, at, value);
}

int butterflyfish_list_ni_insert_all(
        struct butterflyfish_list_ni *const object,
        const uintmax_t at,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_LIST_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->insert_all(object, at, other);
}
