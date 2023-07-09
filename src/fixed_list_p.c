#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_fixed_list_p **) object)

#pragma mark stream_p -

int butterflyfish_fixed_list_p_first(
        const struct butterflyfish_fixed_list_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .stream_p
            .first(object, out);
}

int butterflyfish_fixed_list_p_next(
        const struct butterflyfish_fixed_list_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .stream_p
            .next(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_fixed_list_p_count(
        const struct butterflyfish_fixed_list_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .count(object, out);
}

int butterflyfish_fixed_list_p_last(
        const struct butterflyfish_fixed_list_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .last(object, out);
}

int butterflyfish_fixed_list_p_prev(
        const struct butterflyfish_fixed_list_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .prev(object, item, out);
}

#pragma mark fixed_list_p -

int butterflyfish_fixed_list_p_as_stream(
        const struct butterflyfish_fixed_list_p *const object,
        const struct butterflyfish_stream_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_p *)
            &object->collection_p.stream_p;
    return 0;
}

int butterflyfish_fixed_list_p_as_collection(
        const struct butterflyfish_fixed_list_p *const object,
        const struct butterflyfish_collection_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_p *) &object->collection_p;
    return 0;
}

int butterflyfish_fixed_list_p_get(
        const struct butterflyfish_fixed_list_p *const object,
        const uintmax_t at,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, at, out);
}

int butterflyfish_fixed_list_p_set(
        struct butterflyfish_fixed_list_p *const object,
        uintmax_t at,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->set(object, at, value);
}

int butterflyfish_fixed_list_p_set_item(
        struct butterflyfish_fixed_list_p *object,
        void *const item,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->set_item(object, item, value);
}

int butterflyfish_fixed_list_p_at(
        const struct butterflyfish_fixed_list_p *const object,
        const void *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->at(object, item, out);
}
