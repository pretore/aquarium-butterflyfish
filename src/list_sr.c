#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_list_sr **) object)

#pragma mark stream_sr -

int butterflyfish_list_sr_first(
        const struct butterflyfish_list_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .collection_sr
            .stream_sr
            .first(object, out);
}

int butterflyfish_list_sr_next(
        const struct butterflyfish_list_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .collection_sr
            .stream_sr
            .next(object, item, out);
}

#pragma mark collection_sr -

int butterflyfish_list_sr_count(
        const struct butterflyfish_list_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .collection_sr
            .count(object, out);
}

int butterflyfish_list_sr_last(
        const struct butterflyfish_list_sr *const object,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .collection_sr
            .last(object, out);
}

int butterflyfish_list_sr_prev(
        const struct butterflyfish_list_sr *const object,
        const struct triggerfish_strong *const item,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .collection_sr
            .prev(object, item, out);
}

#pragma mark fixed_list_sr -

int butterflyfish_list_sr_get(
        const struct butterflyfish_list_sr *const object,
        const uintmax_t at,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .get(object, at, out);
}

int butterflyfish_list_sr_set(
        struct butterflyfish_list_sr *const object,
        uintmax_t at,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_LIST_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .set(object, at, value);
}

int butterflyfish_list_sr_set_item(
        struct butterflyfish_list_sr *const object,
        struct triggerfish_strong *const item,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_LIST_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .set_item(object, item, value);
}

int butterflyfish_list_sr_at(
        const struct butterflyfish_list_sr *const object,
        const struct triggerfish_strong *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .fixed_list_sr
            .at(object, item, out);
}

#pragma mark reducible_list_sr -

int butterflyfish_list_sr_remove(
        struct butterflyfish_list_sr *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .remove(object, at);
}

int butterflyfish_list_sr_remove_item(
        struct butterflyfish_list_sr *const object,
        struct triggerfish_strong *const item) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .remove_item(object, item);
}

int butterflyfish_list_sr_remove_all_items(
        struct butterflyfish_list_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->reducible_list_sr
            .remove_all_items(object, other);
}

#pragma mark list_sr -

int butterflyfish_list_sr_add(
        struct butterflyfish_list_sr *const object,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_LIST_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_list_sr_add_all(
        struct butterflyfish_list_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_list_sr_insert(
        struct butterflyfish_list_sr *const object,
        const uintmax_t at,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_LIST_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->insert(object, at, value);
}

int butterflyfish_list_sr_insert_item(
        struct butterflyfish_list_sr *const object,
        struct triggerfish_strong *const item,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_LIST_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->insert_item(object, item, value);
}

int butterflyfish_list_sr_insert_all(
        struct butterflyfish_list_sr *const object,
        const uintmax_t at,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->insert_all(object, at, other);
}

int butterflyfish_list_sr_insert_all_item(
        struct butterflyfish_list_sr *const object,
        struct triggerfish_strong *const item,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_SR_ERROR_ITEM_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_LIST_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->insert_all_item(object, item, other);
}
