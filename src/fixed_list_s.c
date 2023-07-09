#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_fixed_list_s **) object)

#pragma mark stream_s -

int butterflyfish_fixed_list_s_first(
        const struct butterflyfish_fixed_list_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .stream_s
            .first(object, out);
}

int butterflyfish_fixed_list_s_next(
        const struct butterflyfish_fixed_list_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_fixed_list_s_count(
        const struct butterflyfish_fixed_list_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .count(object, out);
}

int butterflyfish_fixed_list_s_last(
        const struct butterflyfish_fixed_list_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .last(object, out);
}

int butterflyfish_fixed_list_s_prev(
        const struct butterflyfish_fixed_list_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_s
            .prev(object, item, out);
}

#pragma mark fixed_list_s -

int butterflyfish_fixed_list_s_as_stream(
        const struct butterflyfish_fixed_list_s *const object,
        const struct butterflyfish_stream_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_s *)
            &object->collection_s.stream_s;
    return 0;
}

int butterflyfish_fixed_list_s_as_collection(
        const struct butterflyfish_fixed_list_s *const object,
        const struct butterflyfish_collection_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_s *) &object->collection_s;
    return 0;
}

int butterflyfish_fixed_list_s_get(
        const struct butterflyfish_fixed_list_s *const object,
        const uintmax_t at,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, at, out);
}

int butterflyfish_fixed_list_s_set(
        struct butterflyfish_fixed_list_s *const object,
        uintmax_t at,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set(object, at, value);
}

int butterflyfish_fixed_list_s_set_item(
        struct butterflyfish_fixed_list_s *const object,
        struct sea_turtle_string *const item,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set_item(object, item, value);
}

int butterflyfish_fixed_list_s_at(
        const struct butterflyfish_fixed_list_s *const object,
        const struct sea_turtle_string *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_FIXED_LIST_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->at(object, item, out);
}
