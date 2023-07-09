#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_ordered_set_s **) object)

#pragma mark stream_s -

int butterflyfish_ordered_set_s_first(
        const struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .collection_s
            .stream_s
            .first(object, out);
}

int butterflyfish_ordered_set_s_next(
        const struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .collection_s
            .stream_s
            .next(object, item, out);
}

#pragma mark collection_s -

int butterflyfish_ordered_set_s_count(
        const struct butterflyfish_ordered_set_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .collection_s
            .count(object, out);
}

int butterflyfish_ordered_set_s_last(
        const struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .collection_s
            .last(object, out);
}

int butterflyfish_ordered_set_s_prev(
        const struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string *const item,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .collection_s
            .prev(object, item, out);
}

#pragma mark set_s -

int butterflyfish_ordered_set_s_add(
        struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set_s
            .add(object, value);
}

int butterflyfish_ordered_set_s_add_all(
        struct butterflyfish_ordered_set_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_s
            .add_all(object, other);
}

int butterflyfish_ordered_set_s_remove(
        struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set_s
            .remove(object, value);
}

int butterflyfish_ordered_set_s_remove_all(
        struct butterflyfish_ordered_set_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_s
            .remove_all(object, other);
}

int butterflyfish_ordered_set_s_remove_item(
        struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string *const item) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->set_s
            .remove_item(object, item);
}

int butterflyfish_ordered_set_s_remove_all_items(
        struct butterflyfish_ordered_set_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_s
            .remove_all_items(object, other);
}

int butterflyfish_ordered_set_s_contains(
        const struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .contains(object, value, out);
}

int butterflyfish_ordered_set_s_contains_all(
        const struct butterflyfish_ordered_set_s *const object,
        const struct butterflyfish_stream_s *const other,
        bool *out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .contains_all(object, other, out);
}

int butterflyfish_ordered_set_s_retain_all(
        struct butterflyfish_ordered_set_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_s
            .retain_all(object, other);
}

int butterflyfish_ordered_set_s_get(
        const struct butterflyfish_ordered_set_s *const object,
        const struct sea_turtle_string *const value,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_s
            .get(object, value, out);
}

#pragma mark ordered_set_s -

int butterflyfish_ordered_set_s_as_stream(
        const struct butterflyfish_ordered_set_s *const object,
        const struct butterflyfish_stream_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_s *)
            &object->set_s.collection_s.stream_s;
    return 0;
}

int butterflyfish_ordered_set_s_as_collection(
        const struct butterflyfish_ordered_set_s *const object,
        const struct butterflyfish_collection_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_s *)
            &object->set_s.collection_s;
    return 0;
}

int butterflyfish_ordered_set_s_as_set(
        struct butterflyfish_ordered_set_s *const object,
        struct butterflyfish_set_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_set_s *) &object->set_s;
    return 0;
}
