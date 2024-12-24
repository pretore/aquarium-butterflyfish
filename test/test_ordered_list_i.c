#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_ordered_list_i *const id;
    void *data;
};

const struct butterflyfish_ordered_list_i ordered_list_i;

static int stream_first(const void *const object,
                        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_list_i == instance->id);
    return mock();
}

static int stream_next(const void *const object,
                       const struct sea_turtle_integer *const item,
                       const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_list_i == instance->id);
    return mock();
}

const struct butterflyfish_stream_i stream_i = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_last(const void *const object,
                const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_list_i == instance->id);
    return mock();
}

static int
collection_prev(const void *const object,
                const struct sea_turtle_integer *const item,
                const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_list_i == instance->id);
    return mock();
}

static int
collection_count(const void *const object, uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_list_i == instance->id);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i collection_i = {
        .as_stream = &stream_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

static int list_get(const void *const object,
                    const uintmax_t at,
                    const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_list_i == instance->id);
    return mock();
}

static int list_at(const void *const object,
                   const struct sea_turtle_integer *const item,
                   uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&ordered_list_i == instance->id);
    return mock();
}

const struct butterflyfish_list_i list_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .get = list_get,
        .at = list_at
};

const struct butterflyfish_ordered_i ordered_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

const struct butterflyfish_ordered_list_i ordered_list_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .as_ordered = &ordered_i,
        .as_list = &list_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .get = list_get,
        .at = list_at
};

static void check_as_stream(void **state) {
    assert_ptr_equal(ordered_list_i.as_stream, &stream_i);
}

static void check_as_collection(void **state) {
    assert_ptr_equal(ordered_list_i.as_collection, &collection_i);
}

static void check_as_ordered(void **state) {
    assert_ptr_equal(ordered_list_i.as_ordered, &ordered_i);
}

static void check_as_list(void **state) {
    assert_ptr_equal(ordered_list_i.as_list, &list_i);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_list_i.count(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_list_i.count((void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    struct instance instance = {
            .id = &ordered_list_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(instance.id->count(&instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_list_i.first(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_list_i.first((void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_list_is_empty(void **state) {
    struct instance instance = {
        .id = &ordered_list_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_list_i.last(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_list_i.last((void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_list_is_empty(void **state) {
    struct instance instance = {
            .id = &ordered_list_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(instance.id->last(&instance, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_list_i.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(ordered_list_i.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_list_i.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &ordered_list_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_list_i.prev(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(ordered_list_i.prev((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_list_i.prev((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &ordered_list_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->prev(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_list_i.get(NULL, 0, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_list_i.get((void *) 1, 0, NULL),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    struct instance instance = {
            .id = &ordered_list_i
    };
    expect_function_call(list_get);
    will_return(list_get,
                BUTTERFLYFISH_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(instance.id->get(&instance, 0, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(ordered_list_i.at(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(ordered_list_i.at((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(ordered_list_i.at((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_item_not_found(void **state) {
    struct instance instance = {
            .id = &ordered_list_i
    };
    expect_function_call(list_at);
    will_return(list_at,
                BUTTERFLYFISH_LIST_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(instance.id->at(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_LIST_I_ERROR_ITEM_NOT_FOUND);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_ordered),
            cmocka_unit_test(check_as_list),
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
            cmocka_unit_test(check_get_error_on_item_not_found),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
