#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_map_ni_ni **) object)

#pragma mark stream_ni_ni -

int butterflyfish_map_ni_ni_first(
        const struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni_ni
            .stream_ni_ni
            .first(object, out);
}

int butterflyfish_map_ni_ni_next(
        const struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni_ni
            .stream_ni_ni
            .next(object, entry, out);
}

#pragma mark collection_ni_ni -

int butterflyfish_map_ni_ni_count(
        const struct butterflyfish_map_ni_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni_ni
            .count(object, out);
}

int butterflyfish_map_ni_ni_last(
        const struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni_ni
            .last(object, out);
}

int butterflyfish_map_ni_ni_prev(
        const struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_ni_ni
            .prev(object, entry, out);
}

#pragma mark map_ni_ni -

int butterflyfish_map_ni_ni_as_stream(
        const struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_ni_ni *)
            &object->collection_ni_ni.stream_ni_ni;
    return 0;
}

int butterflyfish_map_ni_ni_as_collection(
        const struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_collection_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_ni_ni *)
            &object->collection_ni_ni;
    return 0;
}

int butterflyfish_map_ni_ni_remove_entry(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    return INVOKABLE->remove_entry(object, entry);
}

int butterflyfish_map_ni_ni_remove_all_entries(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_entries(object, other);
}

int butterflyfish_map_ni_ni_add(
        struct butterflyfish_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->add(object, key, value);
}

int butterflyfish_map_ni_ni_put(
        struct butterflyfish_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->put(object, key, value);
}

int butterflyfish_map_ni_ni_replace(
        struct butterflyfish_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->replace(object, key, value);
}

int butterflyfish_map_ni_ni_remove(
        struct butterflyfish_map_ni_ni *const object,
        const uintmax_t key) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, key);
}

int butterflyfish_map_ni_ni_add_all(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_map_ni_ni_put_all(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->put_all(object, other);
}

int butterflyfish_map_ni_ni_replace_all(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->replace_all(object, other);
}

int butterflyfish_map_ni_ni_remove_all(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all(object, other);
}

int butterflyfish_map_ni_ni_retain_all(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->retain_all(object, other);
}

int butterflyfish_map_ni_ni_merge(
        struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other,
        int (*const function)(
                const uintmax_t,
                const uintmax_t,
                uintmax_t *)) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    if (!function) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_FUNCTION_IS_NULL;
    }
    return INVOKABLE->merge(object, other, function);
}

int butterflyfish_map_ni_ni_contains_key(
        const struct butterflyfish_map_ni_ni *const object,
        const uintmax_t key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_key(object, key, out);
}

int butterflyfish_map_ni_ni_contains_all_keys(
        const struct butterflyfish_map_ni_ni *const object,
        const struct butterflyfish_stream_ni *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_all_keys(object, other, out);
}

int butterflyfish_map_ni_ni_get(
        const struct butterflyfish_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, key, out);
}

int butterflyfish_map_ni_ni_get_entry(
        const struct butterflyfish_map_ni_ni *const object,
        const uintmax_t key,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get_entry(object, key, out);
}

int butterflyfish_map_ni_ni_keys(
        struct butterflyfish_map_ni_ni *const object,
        struct butterflyfish_set_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->keys(object, out);
}

int butterflyfish_map_ni_ni_values(
        struct butterflyfish_map_ni_ni *const object,
        struct butterflyfish_reducible_list_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->values(object, out);
}
