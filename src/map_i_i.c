#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_map_i_i **) object)

#pragma mark stream_i_i -

int butterflyfish_map_i_i_first(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i_i
            .stream_i_i
            .first(object, out);
}

int butterflyfish_map_i_i_next(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_entry_i_i *const entry,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i_i
            .stream_i_i
            .next(object, entry, out);
}

#pragma mark collection_i_i -

int butterflyfish_map_i_i_count(
        const struct butterflyfish_map_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i_i
            .count(object, out);
}

int butterflyfish_map_i_i_last(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i_i
            .last(object, out);
}

int butterflyfish_map_i_i_prev(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_entry_i_i *const entry,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_i_i
            .prev(object, entry, out);
}

#pragma mark map_i_i -

int butterflyfish_map_i_i_remove_entry(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_entry_i_i *const entry) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    return INVOKABLE->remove_entry(object, entry);
}

int butterflyfish_map_i_i_remove_all_entries(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_entries(object, other);
}

int butterflyfish_map_i_i_add(
        struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, key, value);
}

int butterflyfish_map_i_i_put(
        struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->put(object, key, value);
}

int butterflyfish_map_i_i_replace(
        struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->replace(object, key, value);
}

int butterflyfish_map_i_i_remove(
        struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    return INVOKABLE->remove(object, key);
}

int butterflyfish_map_i_i_add_all(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_map_i_i_put_all(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->put_all(object, other);
}

int butterflyfish_map_i_i_replace_all(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->replace_all(object, other);
}

int butterflyfish_map_i_i_remove_all(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all(object, other);
}

int butterflyfish_map_i_i_retain_all(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->retain_all(object, other);
}

int butterflyfish_map_i_i_merge(
        struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other,
        int (*const function)(
                const struct sea_turtle_integer *,
                const struct sea_turtle_integer *,
                struct sea_turtle_integer **)) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!function) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_FUNCTION_IS_NULL;
    }
    return INVOKABLE->merge(object, other, function);
}

int butterflyfish_map_i_i_contains_key(
        const struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_key(object, key, out);
}

int butterflyfish_map_i_i_contains_all_keys(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_all_keys(object, other, out);
}

int butterflyfish_map_i_i_get(
        const struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, key, out);
}

int butterflyfish_map_i_i_get_entry(
        const struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_entry_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get_entry(object, key, out);
}

int butterflyfish_map_i_i_keys(
        struct butterflyfish_map_i_i *const object,
        struct butterflyfish_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->keys(object, out);
}

int butterflyfish_map_i_i_values(
        struct butterflyfish_map_i_i *const object,
        struct butterflyfish_reducible_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->values(object, out);
}
