#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_set_p **) object)

#pragma mark stream_p -

int butterflyfish_set_p_first(
        const struct butterflyfish_set_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .stream_p
            .first(object, out);
}

int butterflyfish_set_p_next(
        const struct butterflyfish_set_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .stream_p
            .next(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_set_p_count(
        const struct butterflyfish_set_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .count(object, out);
}

int butterflyfish_set_p_last(
        const struct butterflyfish_set_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .last(object, out);
}

int butterflyfish_set_p_prev(
        const struct butterflyfish_set_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p
            .prev(object, item, out);
}

#pragma mark set_p -

int butterflyfish_set_p_add(
        struct butterflyfish_set_p *const object,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_set_p_add_all(
        struct butterflyfish_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_set_p_remove(
        struct butterflyfish_set_p *const object,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, value);
}

int butterflyfish_set_p_remove_all(
        struct butterflyfish_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all(object, other);
}

int butterflyfish_set_p_remove_item(
        struct butterflyfish_set_p *const object,
        const void *const item) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_P_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->remove_item(object, item);
}

int butterflyfish_set_p_remove_all_items(
        struct butterflyfish_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_items(object, other);
}

int butterflyfish_set_p_contains(
        const struct butterflyfish_set_p *const object,
        const void *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains(object, value, out);
}

int butterflyfish_set_p_contains_all(
        const struct butterflyfish_set_p *const object,
        const struct butterflyfish_stream_p *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_all(object, other, out);
}

int butterflyfish_set_p_retain_all(
        struct butterflyfish_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->retain_all(object, other);
}

int butterflyfish_set_p_get(
        const struct butterflyfish_set_p *const object,
        const void *const value,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, value, out);
}
