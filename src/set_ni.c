#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_set_ni **) object)

#pragma mark stream_ni -

int butterflyfish_set_ni_first(
        const struct butterflyfish_set_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .stream_ni
            .first(object, out);
}

int butterflyfish_set_ni_next(
        const struct butterflyfish_set_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .stream_ni
            .next(object, item, out);
}

#pragma mark collection_ni -

int butterflyfish_set_ni_count(
        const struct butterflyfish_set_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .count(object, out);
}

int butterflyfish_set_ni_last(
        const struct butterflyfish_set_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .last(object, out);
}

int butterflyfish_set_ni_prev(
        const struct butterflyfish_set_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni
            .prev(object, item, out);
}

#pragma mark set_ni -

int butterflyfish_set_ni_as_stream(
        const struct butterflyfish_set_ni *const object,
        const struct butterflyfish_stream_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_ni *)
            &object->collection_ni.stream_ni;
    return 0;
}

int butterflyfish_set_ni_as_collection(
        const struct butterflyfish_set_ni *const object,
        const struct butterflyfish_collection_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_ni *) &object->collection_ni;
    return 0;
}

int butterflyfish_set_ni_add(
        struct butterflyfish_set_ni *const object,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_set_ni_add_all(
        struct butterflyfish_set_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_set_ni_remove(
        struct butterflyfish_set_ni *const object,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, value);
}

int butterflyfish_set_ni_remove_all(
        struct butterflyfish_set_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all(object, other);
}

int butterflyfish_set_ni_remove_item(
        struct butterflyfish_set_ni *const object,
        const uintmax_t *const item) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_I_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->remove_item(object, item);
}

int butterflyfish_set_ni_remove_all_items(
        struct butterflyfish_set_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_items(object, other);
}

int butterflyfish_set_ni_contains(
        const struct butterflyfish_set_ni *const object,
        const uintmax_t value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains(object, value, out);
}

int butterflyfish_set_ni_contains_all(
        const struct butterflyfish_set_ni *const object,
        const struct butterflyfish_stream_ni *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_all(object, other, out);
}

int butterflyfish_set_ni_retain_all(
        struct butterflyfish_set_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->retain_all(object, other);
}

int butterflyfish_set_ni_get(
        const struct butterflyfish_set_ni *const object,
        const uintmax_t value,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, value, out);
}
