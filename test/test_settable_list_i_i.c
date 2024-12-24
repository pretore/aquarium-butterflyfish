#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_settable_list_i_i *const id;
    void *data;
};

const struct butterflyfish_settable_list_i_i settable_list_i_i;

static int stream_first(const void *const object,
                        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

static int stream_next(const void *const object,
                       const struct butterflyfish_map_i_i_entry *const item,
                       const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

const struct butterflyfish_stream_i_i stream_i_i = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_last(const void *const object,
                const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

static int
collection_prev(const void *const object,
                const struct butterflyfish_map_i_i_entry *const item,
                const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

static int
collection_count(const void *const object, uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i_i collection_i_i = {
        .as_stream = &stream_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

static int list_get(const void *const object,
                    const uintmax_t at,
                    const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

static int list_at(const void *const object,
                   const struct butterflyfish_map_i_i_entry *const item,
                   uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

const struct butterflyfish_list_i_i list_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .get = list_get,
        .at = list_at
};

static int
settable_set_item(void *const object,
                  const struct butterflyfish_map_i_i_entry *const item,
                  const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

const struct butterflyfish_settable_i_i settable_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .set_item = settable_set_item,
};

static int
settable_list_set(void *const object,
                  uintmax_t at,
                  const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_list_i_i == instance->id);
    return mock();
}

const struct butterflyfish_settable_list_i_i settable_list_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_list = &list_i_i,
        .as_settable = &settable_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .get = list_get,
        .at = list_at,
        .set_item = settable_set_item,
        .set = settable_list_set,
};

static void check_as_stream(void **state) {
    assert_ptr_equal(settable_list_i_i.as_stream, &stream_i_i);
}

static void check_as_collection(void **state) {
    assert_ptr_equal(settable_list_i_i.as_collection, &collection_i_i);
}

static void check_as_list(void **state) {
    assert_ptr_equal(settable_list_i_i.as_list, &list_i_i);
}

static void check_as_settable(void **state) {
    assert_ptr_equal(settable_list_i_i.as_settable, &settable_i_i);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.count(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(settable_list_i_i.count((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(instance.id->count(&instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.first(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(settable_list_i_i.first((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_list_is_empty(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.last(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(settable_list_i_i.last((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_list_is_empty(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(instance.id->last(&instance, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_LIST_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(settable_list_i_i.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(settable_list_i_i.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.prev(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(settable_list_i_i.prev((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(settable_list_i_i.prev((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->prev(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.get(NULL, 0, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(settable_list_i_i.get((void *) 1, 0, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(list_get);
    will_return(list_get,
                BUTTERFLYFISH_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(instance.id->get(&instance, 0, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.at(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(settable_list_i_i.at((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(settable_list_i_i.at((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OUT_IS_NULL);
}

static void check_at_error_on_item_not_found(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(list_at);
    will_return(list_at,
                BUTTERFLYFISH_LIST_I_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(instance.id->at(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_ITEM_NOT_FOUND);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.set(NULL, 0, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(settable_list_i_i.set((void *) 1, 0, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_index_out_of_bounds(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(settable_list_set);
    will_return(settable_list_set,
                BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(instance.id->set(&instance, 0, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(settable_list_set);
    will_return(settable_list_set,
                BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->set(&instance, 0, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_value_is_invalid(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(settable_list_set);
    will_return(settable_list_set,
                BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(instance.id->set(&instance, 0, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(settable_list_i_i.set_item(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(settable_list_i_i.set_item((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_ITEM_IS_NULL);
}

static void check_set_item_error_on_value_is_null(void **state) {
    assert_int_equal(settable_list_i_i.set_item((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_NULL);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->set_item(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    struct instance instance = {
            .id = &settable_list_i_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(instance.id->set_item(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_LIST_I_I_ERROR_VALUE_IS_INVALID);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_list),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_list_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_list_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_at_error_on_object_is_null),
            cmocka_unit_test(check_at_error_on_item_is_null),
            cmocka_unit_test(check_at_error_on_out_is_null),
            cmocka_unit_test(check_at_error_on_item_not_found),
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_value_is_null),
            cmocka_unit_test(check_set_error_on_index_out_of_bounds),
            cmocka_unit_test(check_set_error_on_value_is_invalid),
            cmocka_unit_test(check_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_error_on_object_is_null),
            cmocka_unit_test(check_set_item_error_on_item_is_null),
            cmocka_unit_test(check_set_item_error_on_value_is_null),
            cmocka_unit_test(check_set_item_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_error_on_value_is_invalid),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
