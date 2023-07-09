#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_fixed_list_ni **) object)

#pragma mark stream_ni -

int butterflyfish_fixed_list_ni_first(
        const struct butterflyfish_fixed_list_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .stream_ni
            .first(object, out);
}

int butterflyfish_fixed_list_ni_next(
        const struct butterflyfish_fixed_list_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .stream_ni
            .next(object, item, out);
}

#pragma mark collection_ni -

int butterflyfish_fixed_list_ni_count(
        const struct butterflyfish_fixed_list_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .count(object, out);
}

int butterflyfish_fixed_list_ni_last(
        const struct butterflyfish_fixed_list_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .last(object, out);
}

int butterflyfish_fixed_list_ni_prev(
        const struct butterflyfish_fixed_list_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .prev(object, item, out);
}

#pragma mark fixed_list_ni -

int butterflyfish_fixed_list_ni_as_stream(
        const struct butterflyfish_fixed_list_ni *const object,
        const struct butterflyfish_stream_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_ni *)
            &object->collection_ni.stream_ni;
    return 0;
}

int butterflyfish_fixed_list_ni_as_collection(
        const struct butterflyfish_fixed_list_ni *const object,
        const struct butterflyfish_collection_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_ni *) &object->collection_ni;
    return 0;
}

int butterflyfish_fixed_list_ni_get(
        const struct butterflyfish_fixed_list_ni *const object,
        const uintmax_t at,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, at, out);
}

int butterflyfish_fixed_list_ni_set(
        struct butterflyfish_fixed_list_ni *object,
        uintmax_t at,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->set(object, at, value);
}

int butterflyfish_fixed_list_ni_set_item(
        struct butterflyfish_fixed_list_ni *const object,
        uintmax_t *const item,
        uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->set_item(object, item, value);
}

int butterflyfish_fixed_list_ni_at(
        const struct butterflyfish_fixed_list_ni *const object,
        const uintmax_t *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->at(object, item, out);
}
