#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_i_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_i_i_first((void *) 1, NULL),
            BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL);
}

static int
first_emit_error(const void *const object,
                 const struct butterflyfish_map_entry_i_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_stream_i_i stream_i_i = {
            .first = first_emit_error
    };
    struct object {
        const struct butterflyfish_stream_i_i *stream_i_i;
    };
    struct object instance = {
            .stream_i_i = &stream_i_i
    };
    expect_function_call(first_emit_error);
    will_return(first_emit_error,
                BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_i_i_first(
                    (const struct butterflyfish_stream_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_i_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_i_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STREAM_I_I_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_i_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL);
}

static int
next_emit_error(const void *const object,
                const struct butterflyfish_map_entry_i_i *const item,
                const struct butterflyfish_map_entry_i_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stream_i_i stream_i_i = {
            .next = next_emit_error
    };
    struct object {
        const struct butterflyfish_stream_i_i *stream_i_i;
    };
    struct object instance = {
            .stream_i_i = &stream_i_i
    };
    expect_function_call(next_emit_error);
    will_return(next_emit_error,
                BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_i_i_next(
                    (const struct butterflyfish_stream_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
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
