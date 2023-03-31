#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_reducible_list_s **) object)

#pragma mark stream_s -

int butterflyfish_reducible_list_s_first(
        const struct butterflyfish_reducible_list_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .collection_s
            .stream_s
            .first(object, out);
}

int butterflyfish_reducible_list_s_next(
        const struct butterflyfish_reducible_list_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .collection_s
            .stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_reducible_list_s_count(
        const struct butterflyfish_reducible_list_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .collection_s
            .count(object, out);
}

int butterflyfish_reducible_list_s_last(
        const struct butterflyfish_reducible_list_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .collection_s
            .last(object, out);
}

int butterflyfish_reducible_list_s_prev(
        const struct butterflyfish_reducible_list_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .collection_s
            .prev(object, item, out);
}

#pragma mark fixed_list_s -

int butterflyfish_reducible_list_s_get(
        const struct butterflyfish_reducible_list_s *const object,
        const uintmax_t at,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .get(object, at, out);
}

int butterflyfish_reducible_list_s_set(
        struct butterflyfish_reducible_list_s *const object,
        uintmax_t at,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .set(object, at, value);
}

int butterflyfish_reducible_list_s_set_item(
        struct butterflyfish_reducible_list_s *const object,
        struct sea_turtle_string *const item,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .set_item(object, item, value);
}

int butterflyfish_reducible_list_s_at(
        const struct butterflyfish_reducible_list_s *const object,
        const struct sea_turtle_string *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->fixed_list_s
            .at(object, item, out);
}

#pragma mark reducible_list_s -

int butterflyfish_reducible_list_s_remove(
        struct butterflyfish_reducible_list_s *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, at);
}

int butterflyfish_reducible_list_s_remove_item(
        struct butterflyfish_reducible_list_s *const object,
        const struct sea_turtle_string *const item) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->remove_item(object, item);
}

int butterflyfish_reducible_list_s_remove_all_items(
        struct butterflyfish_reducible_list_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_items(object, other);
}
