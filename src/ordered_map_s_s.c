#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_ordered_map_s_s **) object)

#pragma mark stream_s_s -

int butterflyfish_ordered_map_s_s_first(
        const struct butterflyfish_ordered_map_s_s *const object,
        struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .collection_s_s
            .stream_s_s
            .first(object, out);
}

int butterflyfish_ordered_map_s_s_next(
        const struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_map_entry_s_s *const entry,
        struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .collection_s_s
            .stream_s_s
            .next(object, entry, out);
}

#pragma mark collection_s_s -

int butterflyfish_ordered_map_s_s_count(
        const struct butterflyfish_ordered_map_s_s *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .collection_s_s
            .count(object, out);
}

int butterflyfish_ordered_map_s_s_last(
        const struct butterflyfish_ordered_map_s_s *const object,
        struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .collection_s_s
            .last(object, out);
}

int butterflyfish_ordered_map_s_s_prev(
        const struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_map_entry_s_s *const entry,
        struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .collection_s_s
            .prev(object, entry, out);
}

#pragma mark map_s_s -

int butterflyfish_ordered_map_s_s_remove_entry(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_map_entry_s_s *const entry) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_ENTRY_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .remove_entry(object, entry);
}

int butterflyfish_ordered_map_s_s_remove_all_entries(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .remove_all_entries(object, other);
}

int butterflyfish_ordered_map_s_s_add(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct sea_turtle_string *const key,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .add(object, key, value);
}

int butterflyfish_ordered_map_s_s_put(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct sea_turtle_string *const key,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .put(object, key, value);
}

int butterflyfish_ordered_map_s_s_replace(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct sea_turtle_string *const key,
        const struct sea_turtle_string *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .replace(object, key, value);
}

int butterflyfish_ordered_map_s_s_remove(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct sea_turtle_string *const key) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_KEY_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .remove(object, key);
}

int butterflyfish_ordered_map_s_s_add_all(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .add_all(object, other);
}

int butterflyfish_ordered_map_s_s_put_all(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .put_all(object, other);
}

int butterflyfish_ordered_map_s_s_replace_all(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .replace_all(object, other);
}

int butterflyfish_ordered_map_s_s_remove_all(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .remove_all(object, other);
}

int butterflyfish_ordered_map_s_s_retain_all(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .retain_all(object, other);
}

int butterflyfish_ordered_map_s_s_merge(
        struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s_s *const other,
        int (*const function)(
                const struct sea_turtle_string *,
                const struct sea_turtle_string *,
                struct sea_turtle_string **)) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    if (!function) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_FUNCTION_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .merge(object, other, function);
}

int butterflyfish_ordered_map_s_s_contains_key(
        const struct butterflyfish_ordered_map_s_s *const object,
        const struct sea_turtle_string *const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .contains_key(object, key, out);
}

int butterflyfish_ordered_map_s_s_contains_all_keys(
        const struct butterflyfish_ordered_map_s_s *const object,
        const struct butterflyfish_stream_s *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .contains_all_keys(object, other, out);
}

int butterflyfish_ordered_map_s_s_get(
        const struct butterflyfish_ordered_map_s_s *const object,
        const struct sea_turtle_string *const key,
        const struct sea_turtle_string **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .get(object, key, out);
}

int butterflyfish_ordered_map_s_s_get_entry(
        const struct butterflyfish_ordered_map_s_s *const object,
        const struct sea_turtle_string *const key,
        struct butterflyfish_map_entry_s_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .get_entry(object, key, out);
}

int butterflyfish_ordered_map_s_s_keys(
        struct butterflyfish_ordered_map_s_s *const object,
        struct butterflyfish_set_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .keys(object, out);
}

int butterflyfish_ordered_map_s_s_values(
        struct butterflyfish_ordered_map_s_s *const object,
        struct butterflyfish_reducible_list_s **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MAP_S_S_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->map_s_s
            .values(object, out);
}

#pragma mark ordered_map_s_s -

