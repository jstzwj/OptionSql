

%%
SQL_procedure_statement : SQL_executable_statement;
SQL_executable_statement:
    SQL_schema_statement
     |SQL_data_statement
     |SQL_control_statement
     |SQL_transaction_statement
     |SQL_connection_statement
     |SQL_session_statement
     |SQL_diagnostics_statement
     |SQL_dynamic_statement;

SQL_schema_statement:
    SQL_schema_definition_statement
     |SQL_schema_manipulation_statement;
SQL_schema_definition_statement:
    schema_definition
     |table_definition
     |view_definition
     |SQL-invoked_routine
     |grant_statement
     |role_definition
     |domain_definition
     |character_set_definition
     |collation_definition
     |transliteration_definition
     |assertion_definition
     |trigger_definition
     |user-defined_type_definition
     |user-defined_cast_definition
     |user-defined_ordering_definition
     |transform_definition
     |sequence_generator_definition;
SQL_schema_manipulation_statement:
    drop_schema_statement
     |alter_table_statement
     |drop_table_statement
     |drop_view_statement
     |alter_routine_statement
     |drop_routine_statement
     |drop_user-defined_cast_statement
     |revoke_statement
     |drop_role_statement
     |alter_domain_statement
     |drop_domain_statement
     |drop_character_set_statement
     |drop_collation_statement
     |drop_transliteration_statement
     |drop_assertion_statement
     |drop_trigger_statement
     |alter_type_statement
     |drop_data_type_statement
     |drop_user-defined_ordering_statement
     |alter_transform_statement
     |drop_transform_statement | alter_sequence_generator_statement
     |drop_sequence_generator_statement;
SQL_data_statement:
    open_statement
     |fetch_statement
     |close_statement
     |select_statement_single_row
     |free_locator_statement
     |hold_locator_statement
     |SQL_data_change_statement; 
SQL_data_change_statement:
    delete_statement_positioned
     |delete_statement_searched
     |insert_statement
     |update_statement_positioned
     |update_statement_searched
     |merge_statement;
SQL_control_statement:
    call_statement
     |return_statement;
SQL_transaction_statement:
    start_transaction_statement
     |set_transaction_statement
     |set_constraints_mode_statement
     |savepoint_statement
     |release_savepoint_statement
     |commit_statement
     |rollback_statement;
SQL_connection_statement:
    connect_statement
     |set_connection_statement
     |disconnect_statement;
SQL_session_statement:
    set_session_user_identifier_statement
     |set_role_statement
     |set_local_time_zone_statement
     |set_session_characteristics_statement
     |set_catalog_statement
     |set_schema_statement
     |set_names_statement
     |set_path_statement
     |set_transform_group_statement
     |set_session_collation_statement; 
SQL_diagnostics_statement: get_diagnostics_statement;
SQL_dynamic_statement:
    system_descriptor_statement
     |prepare_statement
     |deallocate_prepared_statement
     |describe_statement
     |execute_statement
     |execute_immediate_statement
     |SQL_dynamic_data_statement;
SQL_dynamic_data_statement:
    allocate_cursor_statement
     |dynamic_open_statement
     |dynamic_fetch_statement
     |dynamic_close_statement
     |dynamic_delete_statement_positioned
     |dynamic_update_statement_positioned;
system_descriptor_statement:
    allocate_descriptor_statement
     |deallocate_descriptor_statement
     |set_descriptor_statement
     |get_descriptor_statement;


table_definition:
        'CREATE TABLE' table_name table_contents_source
        |'CREATE' table_scope 'TABLE' table_name table_contents_source
        |'CREATE TABLE' table_name table_contents_source 'ON COMMIT' table_commit_action 'ROWS'
        |'CREATE' table_scope 'TABLE' table_name table_contents_source
         'ON COMMIT' table_commit_action 'ROWS';

table_scope: global_or_local 'TEMPORARY';

global_or_local: 'GLOBAL' | 'LOCAL';

table_name: local_or_schema_qualified_name;

local_or_schema_qualified_name: [local_or_schema_qualifier period] qualified_identifier;

%%