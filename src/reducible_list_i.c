#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_list_i **) object)

#pragma mark stream_i -

int butterflyfish_reducible_list_i_first(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .collection_i
            .stream_i
            .first(object, out);
}

int butterflyfish_reducible_list_i_next(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .collection_i
            .stream_i
            .next(object, item, out);
}

#pragma mark collection_i -

int butterflyfish_reducible_list_i_count(
        const struct butterflyfish_reducible_list_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .collection_i
            .count(object, out);
}

int butterflyfish_reducible_list_i_last(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .collection_i
            .last(object, out);
}

int butterflyfish_reducible_list_i_prev(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .collection_i
            .prev(object, item, out);
}

#pragma mark fixed_list_i -

int butterflyfish_reducible_list_i_get(
        const struct butterflyfish_reducible_list_i *const object,
        const uintmax_t at,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .get(object, at, out);
}

int butterflyfish_reducible_list_i_set(
        struct butterflyfish_reducible_list_i *object,
        uintmax_t at,
        const struct sea_turtle_integer *value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .set(object, at, value);
}

int butterflyfish_reducible_list_i_at(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_i
            .at(object, item, out);
}

#pragma mark reducible_list_i -

int butterflyfish_reducible_list_i_remove(
        struct butterflyfish_reducible_list_i *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, at);
}

int butterflyfish_reducible_list_i_remove_item(
        struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->remove_item(object, item);
}

int butterflyfish_reducible_list_i_remove_all_items(
        struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_items(object, other);
}
