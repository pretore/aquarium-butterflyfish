#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_sorted_set_p **) object)

#pragma mark stream_p -

int butterflyfish_sorted_set_p_first(
        const struct butterflyfish_sorted_set_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->first
            ? INVOKABLE->first
            : INVOKABLE->ordered_set_p
                    .set_p
                    .collection_p
                    .stream_p
                    .first)(object, out);
}

int butterflyfish_sorted_set_p_next(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->next
            ? INVOKABLE->next
            : INVOKABLE->ordered_set_p
                    .set_p
                    .collection_p
                    .stream_p
                    .next)(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_sorted_set_p_count(
        const struct butterflyfish_sorted_set_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .collection_p
            .count(object, out);
}

int butterflyfish_sorted_set_p_last(
        const struct butterflyfish_sorted_set_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->last
            ? INVOKABLE->last
            : INVOKABLE->ordered_set_p
                    .set_p
                    .collection_p
                    .last)(object, out);
}

int butterflyfish_sorted_set_p_prev(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->prev
            ? INVOKABLE->prev
            : INVOKABLE->ordered_set_p
                    .set_p
                    .collection_p
                    .prev)(object, item, out);
}

#pragma mark set_p -

int butterflyfish_sorted_set_p_add(
        struct butterflyfish_sorted_set_p *const object,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .add(object, value);
}

int butterflyfish_sorted_set_p_add_all(
        struct butterflyfish_sorted_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .add_all(object, other);
}

int butterflyfish_sorted_set_p_remove(
        struct butterflyfish_sorted_set_p *const object,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .remove(object, value);
}

int butterflyfish_sorted_set_p_remove_all(
        struct butterflyfish_sorted_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .remove_all(object, other);
}

int butterflyfish_sorted_set_p_remove_item(
        struct butterflyfish_sorted_set_p *const object,
        const void *const item) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .remove_item(object, item);
}

int butterflyfish_sorted_set_p_remove_all_items(
        struct butterflyfish_sorted_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .remove_all_items(object, other);
}

int butterflyfish_sorted_set_p_contains(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .contains(object, value, out);
}

int butterflyfish_sorted_set_p_contains_all(
        const struct butterflyfish_sorted_set_p *const object,
        const struct butterflyfish_stream_p *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .contains_all(object, other, out);
}

int butterflyfish_sorted_set_p_retain_all(
        struct butterflyfish_sorted_set_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .retain_all(object, other);
}

int butterflyfish_sorted_set_p_get(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const value,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_set_p
            .set_p
            .get(object, value, out);
}

#pragma mark ordered_set_p -
#pragma mark sorted_set_p -

int butterflyfish_sorted_set_p_ceiling(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const value,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ceiling(object, value, out);
}

int butterflyfish_sorted_set_p_floor(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const value,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->floor(object, value, out);
}

int butterflyfish_sorted_set_p_higher(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const value,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->higher(object, value, out);
}

int butterflyfish_sorted_set_p_lower(
        const struct butterflyfish_sorted_set_p *const object,
        const void *const value,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->lower(object, value, out);
}

