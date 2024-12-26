#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_ordered_map_$t$ *const id;
    void *data;
};

const struct butterflyfish_ordered_map_$t$ ordered_map_$t$;

static int stream_first(const void *const object,
                        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

static int stream_next(const void *const object,
                       const $v$const item,
                       const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

const struct butterflyfish_stream_$t$ stream_$t$ = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_last(const void *const object,
                const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

static int
collection_prev(const void *const object,
                const $v$const item,
                const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

static int
collection_count(const void *const object, uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_$t$ collection_$t$ = {
        .as_stream = &stream_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

const struct butterflyfish_set_$t$ set_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

static int
map_contains_key(const void *const object,
                 const $mkv$const key,
                 bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

static int
map_contains_value(const void *const object,
                   const $mvv$const value,
                   bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

static int map_get(const void *const object,
                   const $mkv$const key,
                   const $mvv$*const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

static int
map_get_entry(const void *const object,
              const $mkv$const key,
              const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_map_$t$ == instance->id);
    return mock();
}

const struct butterflyfish_map_$t$ map_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .as_set = &set_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .keys = (void *) 1,
        .values = (void *) 1,
};

const struct butterflyfish_ordered_$t$ ordered_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

const struct butterflyfish_ordered_map_$t$ ordered_map_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .as_set = &set_$t$,
        .as_ordered = &ordered_$t$,
        .as_map = &map_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .keys = (void *) 1,
        .values = (void *) 1,
};

static void check_as_stream(void **state) {
    assert_ptr_equal(ordered_map_$t$.as_stream, &stream_$t$);
}

static void check_as_collection(void **state) {
    assert_ptr_equal(ordered_map_$t$.as_collection, &collection_$t$);
}

static void check_as_set(void **state) {
    assert_ptr_equal(ordered_map_$t$.as_set, &set_$t$);
}

static void check_as_ordered(void **state) {
    assert_ptr_equal(ordered_map_$t$.as_ordered, &ordered_$t$);
}

static void check_as_map(void **state) {
    assert_ptr_equal(ordered_map_$t$.as_map, &map_$t$);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.count(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.count((void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(instance.id->count(&instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.first(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.first((void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_map_is_empty(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MAP_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.last(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.last((void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(instance.id->last(&instance, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MAP_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.prev(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.prev((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.prev((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->prev(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.contains_key(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_key_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.contains_key((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.contains_key((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_contains_key_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(map_contains_key);
    will_return(map_contains_key,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->contains_key(&instance, (void *) 1,(void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_value_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.contains_value(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_value_error_on_value_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.contains_value((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_contains_value_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.contains_value((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_contains_value_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(map_contains_value);
    will_return(map_contains_value,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->contains_value(&instance, (void *) 1,(void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.get(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_key_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.get((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.get((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_key_not_found(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(map_get);
    will_return(map_get,
                BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND);
    assert_int_equal(instance.id->get(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_KEY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(map_get);
    will_return(map_get,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->get(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.get_entry(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_key_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.get_entry((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_map_$t$.get_entry((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_entry_error_on_key_not_found(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND);
    assert_int_equal(instance.id->get_entry(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_KEY_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &ordered_map_$t$,
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->get_entry(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_keys(void **state) {
    assert_ptr_equal(ordered_map_$t$.keys, (void *) 1);
}

static void check_values(void **state) {
    assert_ptr_equal(ordered_map_$t$.values, (void *) 1);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_ordered),
            cmocka_unit_test(check_as_map),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_map_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_map_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_contains_key_error_on_object_is_null),
            cmocka_unit_test(check_contains_key_error_on_key_is_null),
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_value_error_on_object_is_null),
            cmocka_unit_test(check_contains_value_error_on_value_is_null),
            cmocka_unit_test(check_contains_value_error_on_out_is_null),
            cmocka_unit_test(check_contains_value_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_key_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_key_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_keys),
            cmocka_unit_test(check_values),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
