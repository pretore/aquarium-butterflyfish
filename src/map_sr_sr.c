#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_map_sr_sr **) object)

#pragma mark stream_sr_sr -

int butterflyfish_map_sr_sr_first(
        const struct butterflyfish_map_sr_sr *const object,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr_sr
            .stream_sr_sr
            .first(object, out);
}

int butterflyfish_map_sr_sr_next(
        const struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_map_entry_sr_sr *const entry,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr_sr
            .stream_sr_sr
            .next(object, entry, out);
}

#pragma mark collection_sr_sr -

int butterflyfish_map_sr_sr_count(
        const struct butterflyfish_map_sr_sr *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr_sr
            .count(object, out);
}

int butterflyfish_map_sr_sr_last(
        const struct butterflyfish_map_sr_sr *const object,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr_sr
            .last(object, out);
}

int butterflyfish_map_sr_sr_prev(
        const struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_map_entry_sr_sr *const entry,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->collection_sr_sr
            .prev(object, entry, out);
}

#pragma mark map_sr_sr -

int butterflyfish_map_sr_sr_remove_entry(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_map_entry_sr_sr *const entry) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL;
    }
    return INVOKABLE->remove_entry(object, entry);
}

int butterflyfish_map_sr_sr_remove_all_entries(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all_entries(object, other);
}

int butterflyfish_map_sr_sr_add(
        struct butterflyfish_map_sr_sr *const object,
        struct triggerfish_strong *const key,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->add(object, key, value);
}

int butterflyfish_map_sr_sr_put(
        struct butterflyfish_map_sr_sr *const object,
        struct triggerfish_strong *const key,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->put(object, key, value);
}

int butterflyfish_map_sr_sr_replace(
        struct butterflyfish_map_sr_sr *const object,
        struct triggerfish_strong *const key,
        struct triggerfish_strong *const value) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->replace(object, key, value);
}

int butterflyfish_map_sr_sr_remove(
        struct butterflyfish_map_sr_sr *const object,
        struct triggerfish_strong *const key) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL;
    }
    return INVOKABLE->remove(object, key);
}

int butterflyfish_map_sr_sr_add_all(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}

int butterflyfish_map_sr_sr_put_all(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->put_all(object, other);
}

int butterflyfish_map_sr_sr_replace_all(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->replace_all(object, other);
}

int butterflyfish_map_sr_sr_remove_all(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->remove_all(object, other);
}

int butterflyfish_map_sr_sr_retain_all(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr *const other) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->retain_all(object, other);
}

int butterflyfish_map_sr_sr_merge(
        struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr_sr *const other,
        int (*const function)(
                const struct triggerfish_strong *,
                const struct triggerfish_strong *,
                struct triggerfish_strong **)) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    if (!function) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_FUNCTION_IS_NULL;
    }
    return INVOKABLE->merge(object, other, function);
}

int butterflyfish_map_sr_sr_contains_key(
        const struct butterflyfish_map_sr_sr *const object,
        struct triggerfish_strong *const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_key(object, key, out);
}

int butterflyfish_map_sr_sr_contains_all_keys(
        const struct butterflyfish_map_sr_sr *const object,
        const struct butterflyfish_stream_sr *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->contains_all_keys(object, other, out);
}

int butterflyfish_map_sr_sr_get(
        const struct butterflyfish_map_sr_sr *const object,
        struct triggerfish_strong *const key,
        struct triggerfish_strong **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get(object, key, out);
}

int butterflyfish_map_sr_sr_get_entry(
        const struct butterflyfish_map_sr_sr *const object,
        struct triggerfish_strong *const key,
        struct butterflyfish_map_entry_sr_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->get_entry(object, key, out);
}

int butterflyfish_map_sr_sr_keys(
        struct butterflyfish_map_sr_sr *const object,
        struct butterflyfish_set_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->keys(object, out);
}

int butterflyfish_map_sr_sr_values(
        struct butterflyfish_map_sr_sr *const object,
        struct butterflyfish_reducible_list_sr **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->values(object, out);
}
