#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_map_p_p **) object)

#pragma mark stream_p_p -

int butterflyfish_map_p_p_first(
        const struct butterflyfish_map_p_p *const object,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p_p
            .stream_p_p
            .first(object, out);
}

int butterflyfish_map_p_p_next(
        const struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p_p
            .stream_p_p
            .next(object, entry, out);
}

#pragma mark collection_p_p -

int butterflyfish_map_p_p_count(
        const struct butterflyfish_map_p_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p_p
            .count(object, out);
}

int butterflyfish_map_p_p_last(
        const struct butterflyfish_map_p_p *const object,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p_p
            .last(object, out);
}

int butterflyfish_map_p_p_prev(
        const struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_p_p
            .prev(object, entry, out);
}

#pragma mark map_p_p -

int butterflyfish_map_p_p_remove_entry(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_ENTRY_IS_NULL;
    }
    return INVOKABLE->remove_entry(object, entry);
}

int butterflyfish_map_p_p_remove_all_entries(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_entries(object, other);
}

int butterflyfish_map_p_p_add(
        struct butterflyfish_map_p_p *const object,
        const void *const key,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->add(object, key, value);
}

int butterflyfish_map_p_p_put(
        struct butterflyfish_map_p_p *const object,
        const void *const key,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->put(object, key, value);
}

int butterflyfish_map_p_p_replace(
        struct butterflyfish_map_p_p *const object,
        const void *const key,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->replace(object, key, value);
}

int butterflyfish_map_p_p_remove(
        struct butterflyfish_map_p_p *const object,
        const void *const key) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->remove(object, key);
}

int butterflyfish_map_p_p_add_all(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_map_p_p_put_all(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->put_all(object, other);
}

int butterflyfish_map_p_p_replace_all(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->replace_all(object, other);
}

int butterflyfish_map_p_p_remove_all(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all(object, other);
}

int butterflyfish_map_p_p_retain_all(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->retain_all(object, other);
}

int butterflyfish_map_p_p_merge(
        struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other,
        int (*const function)(
                const void *,
                const void *,
                void **)) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    if (!function) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_FUNCTION_IS_NULL;
    }
    return INVOKABLE->merge(object, other, function);
}

int butterflyfish_map_p_p_contains_key(
        const struct butterflyfish_map_p_p *const object,
        const void *const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_key(object, key, out);
}

int butterflyfish_map_p_p_contains_all_keys(
        const struct butterflyfish_map_p_p *const object,
        const struct butterflyfish_stream_p *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_all_keys(object, other, out);
}

int butterflyfish_map_p_p_get(
        const struct butterflyfish_map_p_p *const object,
        const void *const key,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, key, out);
}

int butterflyfish_map_p_p_get_entry(
        const struct butterflyfish_map_p_p *const object,
        const void *const key,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get_entry(object, key, out);
}

int butterflyfish_map_p_p_keys(
        struct butterflyfish_map_p_p *const object,
        struct butterflyfish_set_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->keys(object, out);
}

int butterflyfish_map_p_p_values(
        struct butterflyfish_map_p_p *const object,
        struct butterflyfish_reducible_list_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->values(object, out);
}
