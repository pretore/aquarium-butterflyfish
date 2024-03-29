#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_sorted_set_sr **) object)

#pragma mark stream_sr -

int butterflyfish_sorted_set_sr_first(
        const struct butterflyfish_sorted_set_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->first
            ? INVOKABLE->first
            : INVOKABLE->ordered_set_sr
                    .set_sr
                    .collection_sr
                    .stream_sr
                    .first)(object, out);
}

int butterflyfish_sorted_set_sr_next(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->next
            ? INVOKABLE->next
            : INVOKABLE->ordered_set_sr
                    .set_sr
                    .collection_sr
                    .stream_sr
                    .next)(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_sorted_set_sr_count(
        const struct butterflyfish_sorted_set_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .collection_sr
            .count(object, out);
}

int butterflyfish_sorted_set_sr_last(
        const struct butterflyfish_sorted_set_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->last
            ? INVOKABLE->last
            : INVOKABLE->ordered_set_sr
                    .set_sr
                    .collection_sr
                    .last)(object, out);
}

int butterflyfish_sorted_set_sr_prev(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->prev
            ? INVOKABLE->prev
            : INVOKABLE->ordered_set_sr
                    .set_sr
                    .collection_sr
                    .prev)(object, item, out);
}

#pragma mark set_sr -

int butterflyfish_sorted_set_sr_add(
        struct butterflyfish_sorted_set_sr *const object,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .add(object, value);
}

int butterflyfish_sorted_set_sr_add_all(
        struct butterflyfish_sorted_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .add_all(object, other);
}

int butterflyfish_sorted_set_sr_remove(
        struct butterflyfish_sorted_set_sr *const object,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .remove(object, value);
}

int butterflyfish_sorted_set_sr_remove_all(
        struct butterflyfish_sorted_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .remove_all(object, other);
}

int butterflyfish_sorted_set_sr_remove_item(
        struct butterflyfish_sorted_set_sr *const object,
        struct triggerfish_strong *const item) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .remove_item(object, item);
}

int butterflyfish_sorted_set_sr_remove_all_items(
        struct butterflyfish_sorted_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .remove_all_items(object, other);
}

int butterflyfish_sorted_set_sr_contains(
        const struct butterflyfish_sorted_set_sr *const object,
        struct triggerfish_strong *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .contains(object, value, out);
}

int butterflyfish_sorted_set_sr_contains_all(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct butterflyfish_stream_sr *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .contains_all(object, other, out);
}

int butterflyfish_sorted_set_sr_retain_all(
        struct butterflyfish_sorted_set_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .retain_all(object, other);
}

int butterflyfish_sorted_set_sr_get(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct triggerfish_strong *const value,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_sr
            .set_sr
            .get(object, value, out);
}

#pragma mark ordered_set_sr -
#pragma mark sorted_set_sr -

int butterflyfish_sorted_set_sr_as_stream(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct butterflyfish_stream_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_sr *)
            &object->ordered_set_sr.set_sr.collection_sr.stream_sr;
    return 0;
}

int butterflyfish_sorted_set_sr_as_collection(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct butterflyfish_collection_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_sr *)
            &object->ordered_set_sr.set_sr.collection_sr;
    return 0;
}

int butterflyfish_sorted_set_sr_as_set(
        struct butterflyfish_sorted_set_sr *const object,
        struct butterflyfish_set_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_set_sr *) &object->ordered_set_sr.set_sr;
    return 0;
}

int butterflyfish_sorted_set_sr_as_ordered_set(
        struct butterflyfish_sorted_set_sr *const object,
        struct butterflyfish_ordered_set_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_ordered_set_sr *) &object->ordered_set_sr;
    return 0;
}

int butterflyfish_sorted_set_sr_ceiling(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct triggerfish_strong *const value,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ceiling(object, value, out);
}

int butterflyfish_sorted_set_sr_floor(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct triggerfish_strong *const value,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->floor(object, value, out);
}

int butterflyfish_sorted_set_sr_higher(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct triggerfish_strong *const value,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->higher(object, value, out);
}

int butterflyfish_sorted_set_sr_lower(
        const struct butterflyfish_sorted_set_sr *const object,
        const struct triggerfish_strong *const value,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->lower(object, value, out);
}

