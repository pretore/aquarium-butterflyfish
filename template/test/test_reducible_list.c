#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_reducible_list_$t$ *const id;
    void *data;
};

const struct butterflyfish_reducible_list_$t$ reducible_list_$t$;

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
    seagrass_required_true(&reducible_list_$t$ == instance->id);
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
    seagrass_required_true(&reducible_list_$t$ == instance->id);
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
    seagrass_required_true(&reducible_list_$t$ == instance->id);
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
    seagrass_required_true(&reducible_list_$t$ == instance->id);
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
    seagrass_required_true(&reducible_list_$t$ == instance->id);
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

static int list_get(const void *const object,
                    const uintmax_t at,
                    const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&reducible_list_$t$ == instance->id);
    return mock();
}

static int list_at(const void *const object,
                   const $v$const item,
                   uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&reducible_list_$t$ == instance->id);
    return mock();
}

const struct butterflyfish_list_$t$ list_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .get = list_get,
        .at = list_at
};

static int
reducible_remove_item(void *const object,
                      const $v$const item) {
    if (!object) {
        return BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&reducible_list_$t$ == instance->id);
    return mock();
}

const struct butterflyfish_removable_$t$ removable_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .remove_item = reducible_remove_item,
};

static int
reducible_list_remove(void *const object, const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&reducible_list_$t$ == instance->id);
    return mock();
}

const struct butterflyfish_reducible_list_$t$ reducible_list_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .as_list = &list_$t$,
        .as_removable = &removable_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .get = list_get,
        .at = list_at,
        .remove_item = reducible_remove_item,
        .remove = reducible_list_remove,
};

static void check_as_stream(void **state) {
    assert_ptr_equal(reducible_list_$t$.as_stream, &stream_$t$);
}

static void check_as_collection(void **state) {
    assert_ptr_equal(reducible_list_$t$.as_collection, &collection_$t$);
}

static void check_as_list(void **state) {
    assert_ptr_equal(reducible_list_$t$.as_list, &list_$t$);
}

static void check_as_removable(void **state) {
    assert_ptr_equal(reducible_list_$t$.as_removable, &removable_$t$);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.count(NULL, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.count((void *) 1, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    struct instance instance = {
            .id = &reducible_list_$t$
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(instance.id->count(&instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.first(NULL, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.first((void *) 1, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_list_is_empty(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.last(NULL, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.last((void *) 1, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_list_is_empty(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(instance.id->last(&instance, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_LIST_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.prev(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.prev((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.prev((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->prev(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.get(NULL, 0, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.get((void *) 1, 0, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(list_get);
    will_return(list_get,
                BUTTERFLYFISH_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(instance.id->get(&instance, 0, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.at(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.at((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.at((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_at_error_on_item_not_found(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(list_at);
    will_return(list_at,
                BUTTERFLYFISH_LIST_$T$_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(instance.id->at(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_ITEM_NOT_FOUND);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.remove(NULL, 0),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_remove(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(reducible_list_remove);
    will_return(reducible_list_remove, 0);
    assert_int_equal(instance.id->remove(&instance, 0), 0);
}

static void check_remove_error_on_index_out_of_bounds(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$
    };
    expect_function_call(reducible_list_remove);
    will_return(reducible_list_remove,
                BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(instance.id->remove(&instance, 0),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.remove_item(NULL, (void *) 1),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(reducible_list_$t$.remove_item((void *) 1, NULL),
                     BUTTERFLYFISH_REDUCIBLE_LIST_$T$_ERROR_ITEM_IS_NULL);
}

static void check_remove_item(void **state) {
    struct instance instance = {
            .id = &reducible_list_$t$,
    };
    expect_function_call(reducible_remove_item);
    will_return(reducible_remove_item, 0);
    assert_int_equal(reducible_list_$t$.remove_item(&instance, (void *) 1), 0);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_list),
            cmocka_unit_test(check_as_removable),
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
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove),
            cmocka_unit_test(check_remove_error_on_index_out_of_bounds),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
