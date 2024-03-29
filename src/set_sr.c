#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_set_sr **) object)

#pragma mark stream_sr -

int butterflyfish_set_sr_first(
        const struct butterflyfish_set_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .first(object, out);
}

int butterflyfish_set_sr_next(
        const struct butterflyfish_set_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .stream_sr
            .next(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_set_sr_count(
        const struct butterflyfish_set_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .count(object, out);
}

int butterflyfish_set_sr_last(
        const struct butterflyfish_set_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .last(object, out);
}

int butterflyfish_set_sr_prev(
        const struct butterflyfish_set_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr
            .prev(object, item, out);
}

#pragma mark set_sr -

int butterflyfish_set_sr_as_stream(
        const struct butterflyfish_set_sr *const object,
        const struct butterflyfish_stream_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_sr *)
            &object->collection_sr.stream_sr;
    return 0;
}

int butterflyfish_set_sr_as_collection(
        const struct butterflyfish_set_sr *const object,
        const struct butterflyfish_collection_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_sr *) &object->collection_sr;
    return 0;
}

int butterflyfish_set_sr_add(
        struct butterflyfish_set_sr *const object,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_set_sr_add_all(
        struct butterflyfish_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_set_sr_remove(
        struct butterflyfish_set_sr *const object,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->remove(object, value);
}

int butterflyfish_set_sr_remove_all(
        struct butterflyfish_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all(object, other);
}

int butterflyfish_set_sr_remove_item(
        struct butterflyfish_set_sr *const object,
        struct triggerfish_strong *const item) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_SR_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->remove_item(object, item);
}

int butterflyfish_set_sr_remove_all_items(
        struct butterflyfish_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_items(object, other);
}

int butterflyfish_set_sr_contains(
        const struct butterflyfish_set_sr *const object,
        struct triggerfish_strong *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains(object, value, out);
}

int butterflyfish_set_sr_contains_all(
        const struct butterflyfish_set_sr *const object,
        const struct butterflyfish_stream_sr *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_SR_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_all(object, other, out);
}

int butterflyfish_set_sr_retain_all(
        struct butterflyfish_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->retain_all(object, other);
}

int butterflyfish_set_sr_get(
        const struct butterflyfish_set_sr *const object,
        const struct triggerfish_strong *const value,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, value, out);
}
