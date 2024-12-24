#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_stream_i *const id;
    void *data;
};

const struct butterflyfish_stream_i stream_i;

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
    seagrass_required_true(&stream_i == instance->id);
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
    seagrass_required_true(&stream_i == instance->id);
    return mock();
}

const struct butterflyfish_stream_i stream_i = {
        .first = stream_first,
        .next = stream_next
};

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(stream_i.first(NULL, (void *) 1),
                     BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(stream_i.first((void *) 1, NULL),
                     BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_stream_is_empty(void **state) {
    struct instance instance = {
            .id = &stream_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(stream_i.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(stream_i.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_STREAM_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(stream_i.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &stream_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_stream_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
