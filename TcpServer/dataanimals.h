#ifndef DataSystems_H
#define DataSystems_H

#include <QString>
#include "utils/Utils.h"

#include "db/database.h"

enum DB_check{ SQLITE, PGSQL };

class DataSystems   //Singleton
{
public:

    DataBase *db;

    DB_check db_check;
    bool db_check_create;
    bool exit_application;

    QString db_host;
    QString db_name;
    int db_port;
    int db_connection_counter;
    QString db_login;
    QString db_password;
    QString db_sql_create;
    QString db_sql_insert;
    QString db_sql_drop;

    QString db_sqlite_file;

    QString name_animals;

    QString log="";
    long y;
    QString log_t="";
    QString log_create_db;

    QString settings___color_header;
    QString settings___color_header___decimal;
    QString settings___tabwidget_width;

    QString fileNamePicture;

    static DataSystems& Instance()
    {
        static DataSystems singleton;
        return singleton;
    }

    static DataSystems& I()
    {
        static DataSystems singleton;
        return singleton;
    }

    void clear();

    void cow_card();
    void clear_otel();
    void clear_dry_off();
    void clear_insemenation();
    void clear_batch_transfer();
    void create_milk_separation();

    // Other non-static member functions
private:
    DataSystems() { }                                  // Private constructor
    ~DataSystems() {}
    DataSystems(const DataSystems&);                 // Prevent copy-construction
    DataSystems& operator=(const DataSystems&);      // Prevent assignment

public:

    // 1_1

    // Конфигурация -> Глобальные установки фермы -> Ферма (параметры)
    int DataService_Id;
    QString DataService_FarmDepart;
    QString DataService_counrty;
    QString DataService_lang;
    QString DataService_culture;
    QString DataService_Index;
    QString DataService_street;
    QString DataService_street_number;
    QString DataService_zip_code;
    QString DataService_city;
    QString DataService_telephone;
    QString DataService_owner_name;

    // Ввод данных ->  Дневная запись -> карточки коров
    int dataentry_cow_card_Id;
    QString dataentry_dataentry_cow_card_animals;
    QString dataentry_dataentry_cow_card_responder;
    QString dataentry_dataentry_cow_card_name;
    QString dataentry_dataentry_cow_card_group;
    QString dataentry_dataentry_cow_card_life_number;
    QString dataentry_dataentry_cow_card_present;
    QString dataentry_dataentry_cow_card_birth_date;
    QString dataentry_dataentry_cow_card_location;
    QString dataentry_dataentry_cow_card_label;
    QString dataentry_dataentry_cow_card_keep;
    QString dataentry_dataentry_cow_card_gender;
    QString dataentry_dataentry_cow_card_use_as_sire;
    QString dataentry_dataentry_cow_card_father_life_number;
    QString dataentry_dataentry_cow_card_father_name;
    QString dataentry_dataentry_cow_card_mother_life_number;
    QString dataentry_dataentry_cow_card_mother_name;
    QString dataentry_dataentry_cow_card_hair_color;
    QString dataentry_dataentry_cow_card_gestation;
    QString dataentry_dataentry_cow_card_calm;
    QString dataentry_dataentry_cow_card_blood_type;
    QString dataentry_dataentry_cow_card_percentage;
    QString dataentry_dataentry_cow_card_description;
    QString dataentry_dataentry_cow_card_transfer_in;
    //QString dataentry_dataentry_cow_card_;
    //QString dataentry_dataentry_cow_card_;


    // Ввод данных ->  Дневная запись -> Перевод

    QString transfer_animal_No;
    QString transfer_number;
    QString transfer_Robot_No;
    QString transfer_lactation_No;
    QString transfer_lactation_days;
    QString transfer_days_pregnant;
    QString transfer_present;


    // ************* Параметры Ввод данных -> библиотеки -> Партии  **************************

    int dataentry_library_Id;
    QString dataentry_library_siries_number;
    QString dataentry_library_siries_sire_name;
    QString dataentry_library_siries_life_number;
    QString dataentry_library_siries_sire_code;
    QString dataentry_library_siries_active;

    // ************* Параметры Ввод данных -> библиотеки -> Типы кормления  **************************

    QString dataentry_library_feed_types_number_feed_types;
    QString dataentry_library_feed_types_dry_matter;
    QString dataentry_library_feed_types_name;
    QString dataentry_library_feed_types_active;
    QString dataentry_library_feed_types_type;
    QString dataentry_library_feed_types_remark;

    // ************* Параметры Ввод данных -> библиотеки -> Основной перевод **************************

    QString dataentry_library_batch_transfer_animals;
    QString dataentry_library_batch_transfer_responder;
    QString dataentry_library_batch_transfer_life_number;
    QString dataentry_library_batch_transfer_birth_date;
    QString dataentry_library_batch_transfer_location;
    QString dataentry_library_batch_transfer_calving_date;
    QString dataentry_library_batch_transfer_insemenation_date;



    //QString dataentry_library_siries_sire_code;
    //******************* Параметры отела **********************
    // basic data
    QString otel_animal_No;
    QString otel_number;
    QString otel_Robot_No;
    QString otel_lactation_No;
    QString otel_lactation_days;
    QString otel_days_pregnant;
    QString otel_lactation_production;
    QString otel_average_lactation;
    QString otel_average_refusals;
    QString otel_average_falures;
    QString otel_average_milk_speed;
    // расширенные
    QString otel_current_location; // 1 calving
    QString otel_days_dry;
    QString otel_waiting_time_dry_off;
    QString otel_remarks_previous;
    QString otel_expected_calving;
    QString otel_calving_date;
    QString otel_waiting_time_colostrum;
    QString otel_number_of_calves;
    QString otel_remarks;
    QString otel_group;
    QString otel_cow_number;
    QString otel_responder;
    QString otel_teat;
    QString otel_separation_milk_tank;
    QString otel_calf_born_dead; // 2 calf 1
    QString otel_calf_keep_calf;
    QString otel_calf_calf_number;
    QString otel_calf_life_number;
    QString otel_calf_name;
    QString otel_calf_weight;
    QString otel_calf_sex;
    QString otel_calf_hair_color;
    QString otel_calf_group;

   // ******************* Параметры Сухостойность *****************************
    QString dry_off_animal_No;
    //QString dry_off_number;
    QString dry_off_Robot_number;
    QString dry_off_lactation_number;
    QString dry_off_lactation_days;
    QString dry_off_days_pregnant;
    QString dry_off_day_production;
    QString dry_off_total_day;
    QString dry_off_udder_health_add;
    QString dry_off_udder_health_add_count;

    QString dry_off_date;
    QString dry_off_medicine_used;
    QString dry_off_medicine_category;
    QString dry_off_medicine;
    QString dry_off_dosage;
    QString dry_off_Teat_LF;
    QString dry_off_Teat_RF;
    QString dry_off_Teat_LR;
    QString dry_off_Teat_RR;
    QString dry_off_separate_meat_untill;
    QString dry_off_separate_milk_untill;
    QString dry_off_group;




    // ************** Параметры Осеменение **********************
    QString Insemenation_animal_No;
    QString Insemenation_Robot_number;
    QString Insemenation_lactation_number;
    QString Insemenation_lactation_days;
    QString Insemenation_since_insemenation;
    QString Insemenation_insemenation_number;
    QString Insemenation_day_production;
    QString Insemenation_Activity;
    QString Insemenation_days_since_heat;

    QString Insemenation_expected_otel;

    QString Insemenation_type;
    QString Insemenation_date;
    QString Insemenation_sire;
    QString Insemenation_person;
    QString Insemenation_group;
    QString Insemenation_remarks;


    // ****************** Параметры сепарации молока ******************************
    QString milk_separation_animal_No;
    QString milk_separation_Robot_number;
    QString milk_separation_lactation_number;
    QString milk_separation_lactation_days;
    QString milk_separation_milk_separation_type;
    QString milk_separation_milk_separation_tank;
    QString milk_separation_end_date;
    QString milk_separation_milk_separation_status;
    QString milk_separation_start_separation_y;
    QString milk_separation_start_separation_h;
    QString milk_separation_end_separation_y;
    QString milk_separation_end_separation_h;
    QString milk_separation_expected_dry;


    // ******************* Параметры Настройки лактации *****************************
    QString milk_settings_animal_No;
    QString milk_settings_Robot_number;
    QString milk_settings_lactation_number;
    QString milk_settings_lactation_days;
    QString milk_settings_priority_feeding;
    QString milk_settings_milk_teat_lf;
    QString milk_settings_milk_teat_lr;
    QString milk_settings_milk_teat_rf;
    QString milk_settings_milk_teat_rr;
    QString milk_settings_milk_under_supervision;
    QString milk_settings_training_period;

    // ******************* Маршрутиазция *****************************

    QString routing_animal_No;
    QString routing_Robot_number;
    QString routing_lactation_number;
    QString routing_lactation_days;
    QString routing_area;
    QString routing_from_date;
    QString routing_till_date;
    QString routing_from_till_time;
    QString routing_active_routing;

    // ******************* Параметры Robota *****************************
    QString robot_coord_teat_lf;
    QString robot_coord_teat_lr;
    QString robot_coord_teat_rf;
    QString robot_coord_teat_rr;
    QString robot_param1;
    QString robot_param2;
    QString robot_param3;
    QString robot_param4;

    // *******************************************************************************

    //Ввод данных (Data entry) 2. Меню: Настройки (Settings) 3. Вкладка: Доение – Общее доение (Milking – General Milking)

    QString dataentry_settings____milking__general_milking__colostrum_day;
    QString dataentry_settings____milking__general_milking__milk_destination;
    QString dataentry_settings____milking__general_milking__separation_milk_destination; // пункт назначения сепарационного молока
    QString dataentry_settings____milking__general_milking__milk_teat_lf;                // соска для молока (да/нет)
    QString dataentry_settings____milking__general_milking__milk_teat_lr;                // соска для молока (да/нет)
    QString dataentry_settings____milking__general_milking__milk_teat_rf;                // соска для молока (да/нет)
    QString dataentry_settings____milking__general_milking__milk_teat_rr;                // соска для молока (да/нет)
    QString dataentry_settings____milking__general_milking__reset_teat_coordinates_aftre_dry; // сброс координат сосков после сухостойности // (да/нет)
    QString dataentry_settings____milking__general_milking__training_period;                  // (да/нет)
    QString dataentry_settings____milking__general_milking__milk_under_supervision;  // лактация под управлением // (да/нет)
    QString dataentry_settings____milking__general_milking__optimal_sampling_period; // оптимальный пробный период
    QString dataentry_settings____milking__general_milking__teat_position_known;     // позиции сосков известны // (да/нет)
    QString dataentry_settings____milking__general_milking__correction_time;
    QString dataentry_settings____milking__general_milking__alternative_connection_method; // альтернативный способ связи (да/нет)

    // *****************************************************************************************
    //     //Ввод данных (Data entry) 2. Меню: Настройки (Settings) 3. Вкладка: Доение –  После доения (Milking – after milking

    QString dataentry_settings____milking__post_milking__number_of_treatments_lf;    // количество процедур
    QString dataentry_settings____milking__post_milking__number_of_treatments_lr;
    QString dataentry_settings____milking__post_milking__number_of_treatments_rf;
    QString dataentry_settings____milking__post_milking__number_of_treatments_rr;
    QString dataentry_settings____milking__post_milking__duration_per_treatment_lf;  // продолжительность процедуры - секунды
    QString dataentry_settings____milking__post_milking__duration_per_treatment_lr;
    QString dataentry_settings____milking__post_milking__duration_per_treatment_rf;
    QString dataentry_settings____milking__post_milking__duration_per_treatment_rr;
    QString dataentry_settings____milking__post_milking__sampling;                   // способ (да/нет)
    QString dataentry_settings____milking__post_milking__clean_milk_equipment;       // чистое молочное оборудование
    QString dataentry_settings____milking__post_milking__priority_feeding;           // приоритетное кормление (да/нет)

    //*********************

    map_json_prop mj;
    map_json_prop_json mjpj;
    map_db_sql db_sql;
    map_db_sql db_sql_table_insert;

    QString RIndication_RecordId;
    QString RIndication_Type;
    QString RIndication_IndicationId;
    QString RIndication_CreationTime;
    QString RIndication_DTViewed;
    QString RIndication_Parameter1;
    QString RIndication_Parameter2;
    QString RIndication_Parameter3;
    QString RIndication_Parameter4;


    //*********************

    QString RTransmitBuffer_Dest;
    QString RTransmitBuffer_Code;
    QString RTransmitBuffer_Crc;
    QString RTransmitBuffer_Length;
    QString RTransmitBuffer_TabId;
    QString RTransmitBuffer_D00;
    QString RTransmitBuffer_D01;
    QString RTransmitBuffer_D02;
    QString RTransmitBuffer_D03;
    QString RTransmitBuffer_D04;
    QString RTransmitBuffer_D05;
    QString RTransmitBuffer_D06;
    QString RTransmitBuffer_D07;
    QString RTransmitBuffer_D08;
    QString RTransmitBuffer_D09;
    QString RTransmitBuffer_D10;
    QString RTransmitBuffer_D11;
    QString RTransmitBuffer_D12;
    QString RTransmitBuffer_D13;
    QString RTransmitBuffer_D14;
    QString RTransmitBuffer_D15;
    QString RTransmitBuffer_D16;
    QString RTransmitBuffer_D17;
    QString RTransmitBuffer_D18;
    QString RTransmitBuffer_D19;
    QString RTransmitBuffer_D20;
    QString RTransmitBuffer_D21;
    QString RTransmitBuffer_D22;
    QString RTransmitBuffer_D23;
    QString RTransmitBuffer_D24;
    QString RTransmitBuffer_D25;
    QString RTransmitBuffer_D26;
    QString RTransmitBuffer_D27;
    QString RTransmitBuffer_D28;
    QString RTransmitBuffer_D29;
    QString RTransmitBuffer_D30;
    QString RTransmitBuffer_D31;
    QString RTransmitBuffer_D32;
    QString RTransmitBuffer_D33;
    QString RTransmitBuffer_D34;
    QString RTransmitBuffer_D35;
    QString RTransmitBuffer_D36;
    QString RTransmitBuffer_D37;
    QString RTransmitBuffer_D38;
    QString RTransmitBuffer_D39;
    QString RTransmitBuffer_D40;
    QString RTransmitBuffer_D41;
    QString RTransmitBuffer_D42;
    QString RTransmitBuffer_D43;
    QString RTransmitBuffer_D44;
    QString RTransmitBuffer_D45;
    QString RTransmitBuffer_D46;
    QString RTransmitBuffer_D47;
    QString RTransmitBuffer_D48;
    QString RTransmitBuffer_D49;
    QString RTransmitBuffer_D50;
    QString RTransmitBuffer_D51;
    QString RTransmitBuffer_D52;
    QString RTransmitBuffer_D53;
    QString RTransmitBuffer_D54;
    QString RTransmitBuffer_D55;
    QString RTransmitBuffer_D56;
    QString RTransmitBuffer_D57;
    QString RTransmitBuffer_D58;
    QString RTransmitBuffer_D59;
    QString RTransmitBuffer_D60;
    QString RTransmitBuffer_D61;
    QString RTransmitBuffer_D62;
    QString RTransmitBuffer_D63;
    QString RTransmitBuffer_D64;
    QString RTransmitBuffer_D65;
    QString RTransmitBuffer_D66;
    QString RTransmitBuffer_D67;
    QString RTransmitBuffer_D68;
    QString RTransmitBuffer_D69;
    QString RTransmitBuffer_D70;
    QString RTransmitBuffer_D71;
    QString RTransmitBuffer_D72;
    QString RTransmitBuffer_D73;
    QString RTransmitBuffer_D74;
    QString RTransmitBuffer_D75;
    QString RTransmitBuffer_D76;
    QString RTransmitBuffer_D77;
    QString RTransmitBuffer_D78;
    QString RTransmitBuffer_D79;
    QString RTransmitBuffer_D80;
    QString RTransmitBuffer_D81;
    QString RTransmitBuffer_D82;
    QString RTransmitBuffer_D83;
    QString RTransmitBuffer_D84;
    QString RTransmitBuffer_D85;
    QString RTransmitBuffer_D86;
    QString RTransmitBuffer_D87;
    QString RTransmitBuffer_D88;
    QString RTransmitBuffer_D89;
    QString RTransmitBuffer_D90;
    QString RTransmitBuffer_D91;
    QString RTransmitBuffer_D92;
    QString RTransmitBuffer_D93;
    QString RTransmitBuffer_D94;
    QString RTransmitBuffer_D95;
    QString RTransmitBuffer_D96;
    QString RTransmitBuffer_D97;
    QString RTransmitBuffer_D98;
    QString RTransmitBuffer_D99;
    QString RTransmitBuffer_D100;
    QString RTransmitBuffer_D101;
    QString RTransmitBuffer_D102;
    QString RTransmitBuffer_D103;
    QString RTransmitBuffer_D104;
    QString RTransmitBuffer_D105;
    QString RTransmitBuffer_D106;
    QString RTransmitBuffer_D107;
    QString RTransmitBuffer_D108;
    QString RTransmitBuffer_D109;
    QString RTransmitBuffer_D110;
    QString RTransmitBuffer_D111;
    QString RTransmitBuffer_D112;
    QString RTransmitBuffer_D113;
    QString RTransmitBuffer_D114;
    QString RTransmitBuffer_D115;
    QString RTransmitBuffer_D116;
    QString RTransmitBuffer_D117;
    QString RTransmitBuffer_D118;
    QString RTransmitBuffer_D119;
    QString RTransmitBuffer_D120;
    QString RTransmitBuffer_D121;
    QString RTransmitBuffer_D122;
    QString RTransmitBuffer_D123;
    QString RTransmitBuffer_D124;
    QString RTransmitBuffer_D125;
    QString RTransmitBuffer_D126;
    QString RTransmitBuffer_D127;
    QString RTransmitBuffer_D128;
    QString RTransmitBuffer_D129;
    QString RTransmitBuffer_D130;
    QString RTransmitBuffer_D131;
    QString RTransmitBuffer_D132;
    QString RTransmitBuffer_D133;
    QString RTransmitBuffer_D134;
    QString RTransmitBuffer_D135;
    QString RTransmitBuffer_D136;
    QString RTransmitBuffer_D137;
    QString RTransmitBuffer_D138;
    QString RTransmitBuffer_D139;
    QString RTransmitBuffer_D140;
    QString RTransmitBuffer_D141;
    QString RTransmitBuffer_D142;
    QString RTransmitBuffer_D143;
    QString RTransmitBuffer_D144;
    QString RTransmitBuffer_D145;
    QString RTransmitBuffer_D146;
    QString RTransmitBuffer_D147;
    QString RTransmitBuffer_D148;
    QString RTransmitBuffer_D149;
    QString RTransmitBuffer_D150;
    QString RTransmitBuffer_D151;
    QString RTransmitBuffer_D152;
    QString RTransmitBuffer_D153;
    QString RTransmitBuffer_D154;
    QString RTransmitBuffer_D155;
    QString RTransmitBuffer_D156;
    QString RTransmitBuffer_D157;
    QString RTransmitBuffer_D158;
    QString RTransmitBuffer_D159;
    QString RTransmitBuffer_D160;
    QString RTransmitBuffer_D161;
    QString RTransmitBuffer_D162;
    QString RTransmitBuffer_D163;
    QString RTransmitBuffer_D164;
    QString RTransmitBuffer_D165;
    QString RTransmitBuffer_D166;
    QString RTransmitBuffer_D167;
    QString RTransmitBuffer_D168;
    QString RTransmitBuffer_D169;
    QString RTransmitBuffer_D170;
    QString RTransmitBuffer_D171;
    QString RTransmitBuffer_D172;
    QString RTransmitBuffer_D173;
    QString RTransmitBuffer_D174;
    QString RTransmitBuffer_D175;
    QString RTransmitBuffer_D176;
    QString RTransmitBuffer_D177;
    QString RTransmitBuffer_D178;
    QString RTransmitBuffer_D179;
    QString RTransmitBuffer_D180;
    QString RTransmitBuffer_D181;
    QString RTransmitBuffer_D182;
    QString RTransmitBuffer_D183;
    QString RTransmitBuffer_D184;
    QString RTransmitBuffer_D185;
    QString RTransmitBuffer_D186;
    QString RTransmitBuffer_D187;
    QString RTransmitBuffer_D188;
    QString RTransmitBuffer_D189;
    QString RTransmitBuffer_D190;
    QString RTransmitBuffer_D191;
    QString RTransmitBuffer_D192;
    QString RTransmitBuffer_D193;
    QString RTransmitBuffer_D194;
    QString RTransmitBuffer_D195;
    QString RTransmitBuffer_D196;
    QString RTransmitBuffer_D197;
    QString RTransmitBuffer_D198;
    QString RTransmitBuffer_D199;
    QString RTransmitBuffer_D150_;
    QString RTransmitBuffer_D151_;
    QString RTransmitBuffer_D152_;
    QString RTransmitBuffer_D153_;
    QString RTransmitBuffer_D154_;
    QString RTransmitBuffer_D155_;
    QString RTransmitBuffer_D156_;
    QString RTransmitBuffer_D157_;
    QString RTransmitBuffer_D158_;
    QString RTransmitBuffer_D159_;
    QString RTransmitBuffer_D160_;
    QString RTransmitBuffer_D161_;
    QString RTransmitBuffer_D162_;
    QString RTransmitBuffer_D163_;
    QString RTransmitBufferD164_;


    //*******************************************


    QString RMilkSettings_TagId;
    QString RMilkSettings_StructId;
    QString RMilkSettings_MilkingAllowed;
    QString RMilkSettings_CreationTime;
    QString RMilkSettings_MinMilkInterval;
    QString RMilkSettings_ForcedCleaning;
    QString RMilkSettings_MilkAction;
    QString RMilkSettings_MilkDestination;
    QString RMilkSettings_SCCSampling;
    QString RMilkSettings_TakeOffMethod;
    QString RMilkSettings_PulsMethodMilking;
    QString RMilkSettings_MilkMethod;
    QString RMilkSettings_MilkSampling;
    QString RMilkSettings_Calved;
    QString RMilkSettings_AltConnMethod;
    QString RMilkSettings_VacuumLevel;
    QString RMilkSettings_MaxConnectTime;
    QString RMilkSettings_MaxConnections;
    QString RMilkSettings_CleaningOrder;
    QString RMilkSettings_CleaningTimeLR;
    QString RMilkSettings_CleaningTimeRR;
    QString RMilkSettings_CleaningTimeRF;
    QString RMilkSettings_CleaningTimeLF;
    QString RMilkSettings_CleaningIterLR;
    QString RMilkSettings_CleaningIterRR;
    QString RMilkSettings_CleaningIterRF;
    QString RMilkSettings_CleaningIterLF;
    QString RMilkSettings_PulsFreqLR;
    QString RMilkSettings_PulsFreqRR;
    QString RMilkSettings_PulsFreqRF;
    QString RMilkSettings_PulsFreqLF;
    QString RMilkSettings_PulsRatioLR;
    QString RMilkSettings_PulsRatioRR;
    QString RMilkSettings_PulsRatioRF;
    QString RMilkSettings_PulsRatioLF;
    QString RMilkSettings_DisIterLR;
    QString RMilkSettings_DisIterRR;
    QString RMilkSettings_DisIterRF;
    QString RMilkSettings_DisIterLF;
    QString RMilkSettings_DisTimeLR;
    QString RMilkSettings_DisTimeRR;
    QString RMilkSettings_DisTimeRF;
    QString RMilkSettings_DisTimeLF;
    QString RMilkSettings_BlockTimeStart1;
    QString RMilkSettings_BlockDuration1;
    QString RMilkSettings_BlockTimeStart2;
    QString RMilkSettings_BlockDuration2;
    QString RMilkSettings_StartTimeMilkSampling;
    QString RMilkSettings_StartTimeSCCSampling;


    //******************************************************


    QString RFeedVisit_TagId;
    QString RFeedVisit_StructId;
    QString RFeedVisit_NrOfFeedTypes;
    QString RFeedVisit_VisitId;
    QString RFeedVisit_SeqNr;
    QString RFeedVisit_StartFeedVisitTime;
    QString RFeedVisit_EndFeedVisitTime;
    QString RFeedVisit_SettingTime;
    QString RFeedVisit_TroughId;
    QString RFeedVisit_Free;
    QString RFeedVisit_RemindTime;
    QString RFeedVisit_RemindTrough;
    QString RFeedVisit_CowType;
    QString RFeedVisit_StuffRate;
    QString RFeedVisit_FeedId1;
    QString RFeedVisit_Nu1;
    QString RFeedVisit_LastFeedVisitTime1;
    QString RFeedVisit_CurrentPeriodAmount1;
    QString RFeedVisit_Credit1;
    QString RFeedVisit_TakeIn1;
    QString RFeedVisit_FeedId2;
    QString RFeedVisit_Nu2;
    QString RFeedVisit_LastFeedVisitTime2;
    QString RFeedVisit_CurrentPeriodAmount2;
    QString RFeedVisit_Credit2;
    QString RFeedVisit_TakeIn2;
    QString RFeedVisit_FeedId3;
    QString RFeedVisit_Nu3;
    QString RFeedVisit_LastFeedVisitTime3;
    QString RFeedVisit_CurrentPeriodAmount3;
    QString RFeedVisit_Credit3;
    QString RFeedVisit_TakeIn3;
    QString RFeedVisit_FeedId4;
    QString RFeedVisit_NU4;
    QString RFeedVisit_LastFeedVisitTime4;
    QString RFeedVisit_CurrentPeriodAmount4;
    QString RFeedVisit_Credit4;
    QString RFeedVisit_TakeIn4;
    QString RFeedVisit_FeedId5;
    QString RFeedVisit_NU5;
    QString RFeedVisit_LastFeedVisitTime5;
    QString RFeedVisit_CurrentPeriodAmount5;
    QString RFeedVisit_Credit5;
    QString RFeedVisit_TakeIn5;
    QString RFeedVisit_FeedId6;
    QString RFeedVisit_NU6;
    QString RFeedVisit_LastFeedVisitTime6;
    QString RFeedVisit_CurrentPeriodAmount6;
    QString RFeedVisit_Credit6;
    QString RFeedVisit_TakeIn6;
    QString RFeedVisit_FeedId7;
    QString RFeedVisit_NU7;
    QString RFeedVisit_LastFeedVisitTime7;
    QString RFeedVisit_CurrentPeriodAmount7;
    QString RFeedVisit_Credit7;
    QString RFeedVisit_TakeIn7;
    QString RFeedVisit_FeedId8;
    QString RFeedVisit_NU8;
    QString RFeedVisit_LastFeedVisitTime8;
    QString RFeedVisit_CurrentPeriodAmount8;
    QString RFeedVisit_Credit8;
    QString RFeedVisit_TakeIn8;
    QString RFeedVisit_FeedId9;
    QString RFeedVisit_NU9;
    QString RFeedVisit_LastFeedVisitTime9;
    QString RFeedVisit_CurrentPeriodAmount9;
    QString RFeedVisit_Credit9;
    QString RFeedVisit_TakeIn9;
    QString RFeedVisit_Free_;

    //*******************

    QString RMilkVisit_TagId;
    QString RMilkVisit_StructId;
    QString RMilkVisit_ChangedSettings;
    QString RMilkVisit_VisitId;
    QString RMilkVisit_SettingTime;
    QString RMilkVisit_StartMilkVisitTime;
    QString RMilkVisit_EndMilkVisitTime;
    QString RMilkVisit_LastSucceedMilkTime;
    QString RMilkVisit_MilkingResult;
    QString RMilkVisit_ConsecFailes;
    QString RMilkVisit_AvgVisitTime;
    QString RMilkVisit_MilkYield;
    QString RMilkVisit_MilkYieldExp;
    QString RMilkVisit_BottleNumber;
    QString RMilkVisit_RackNumber;
    QString RMilkVisit_MilkTemperature;
    QString RMilkVisit_MilkSpeedMax;
    QString RMilkVisit_DeadMilkTimeLR;
    QString RMilkVisit_DeadMilkTimeRR;
    QString RMilkVisit_DeadMilkTimeRF;
    QString RMilkVisit_DeadMilkTimeLF;
    QString RMilkVisit_DeadMilkTimeAvgLR;
    QString RMilkVisit_DeadMilkTimeAvgRR;
    QString RMilkVisit_DeadMilkTimeAvgRF;
    QString RMilkVisit_DeadMilkTimeAvgLF;
    QString RMilkVisit_MilkTimeLR;
    QString RMilkVisit_MilkTimeRR;
    QString RMilkVisit_MilkTimeRF;
    QString RMilkVisit_MilkTimeLF;
    QString RMilkVisit_YieldLR;
    QString RMilkVisit_YieldRR;
    QString RMilkVisit_YieldRF;
    QString RMilkVisit_YieldLF;
    QString RMilkVisit_RankLR;
    QString RMilkVisit_RankRR;
    QString RMilkVisit_RankRF;
    QString RMilkVisit_RankLF;
    QString RMilkVisit_RankDevLR;
    QString RMilkVisit_RankDevRR;
    QString RMilkVisit_RankDevRF;
    QString RMilkVisit_RankDevLF;
    QString RMilkVisit_XPosAvgLR;
    QString RMilkVisit_XPosAvgRR;
    QString RMilkVisit_XPosAvgRF;
    QString RMilkVisit_XPosAvgLF;
    QString RMilkVisit_YPosAvgLR;
    QString RMilkVisit_YPosAvgRR;
    QString RMilkVisit_YPosAvgRF;
    QString RMilkVisit_YPosAvgLF;
    QString RMilkVisit_ZPosAvgLR;
    QString RMilkVisit_ZPosAvgRR;
    QString RMilkVisit_ZPosAvgRF;
    QString RMilkVisit_ZPosAvgLF;
    QString RMilkVisit_LengthLR;
    QString RMilkVisit_LengthRR;
    QString RMilkVisit_LengthRF;
    QString RMilkVisit_LengthLF;
    QString RMilkVisit_WidthLR;
    QString RMilkVisit_WidthRR;
    QString RMilkVisit_WidthRF;
    QString RMilkVisit_WidthLF;
    QString RMilkVisit_AttachmentsLR;
    QString RMilkVisit_AttachmentsRR;
    QString RMilkVisit_AttachmentsRF;
    QString RMilkVisit_AttachmentsLF;
    QString RMilkVisit_ConductivityLR;
    QString RMilkVisit_ConductivityRR;
    QString RMilkVisit_ConductivityRF;
    QString RMilkVisit_ConductivityLF;
    QString RMilkVisit_ConductivityMAvgLR;
    QString RMilkVisit_ConductivityMAvgRR;
    QString RMilkVisit_ConductivityMAvgRF;
    QString RMilkVisit_ConductivityMAvgLF;
    QString RMilkVisit_RedReflectionLR;
    QString RMilkVisit_RedReflectionRR;
    QString RMilkVisit_RedReflectionRF;
    QString RMilkVisit_RedReflectionLF;
    QString RMilkVisit_GreenReflectionLR;
    QString RMilkVisit_GreenReflectionRR;
    QString RMilkVisit_GreenReflectionRF;
    QString RMilkVisit_GreenReflectionLF;
    QString RMilkVisit_BlueReflectionLR;
    QString RMilkVisit_BlueReflectionRR;
    QString RMilkVisit_BlueReflectionRF;
    QString RMilkVisit_BlueReflectionLF;
    QString RMilkVisit_BackColorLR;
    QString RMilkVisit_BackColorRR;
    QString RMilkVisit_BackColorRF;
    QString RMilkVisit_BackColorLF;
    QString RMilkVisit_AttMastitis;
    QString RMilkVisit_AttBlood;
    QString RMilkVisit_AttColostrum;
    QString RMilkVisit_AttAbnormal;
    QString RMilkVisit_AttFirstMilkAbnormal;
    QString RMilkVisit_AttConductivity;
    QString RMilkVisit_AvgMilkPerHourLR;
    QString RMilkVisit_AvgMilkPerHourRR;
    QString RMilkVisit_AvgMilkPerHourRF;
    QString RMilkVisit_AvgMilkPerHourLF;
    QString RMilkVisit_FailedMilkYieldLR;
    QString RMilkVisit_FailedMilkYieldRR;
    QString RMilkVisit_FailedMilkYieldRF;
    QString RMilkVisit_FailedMilkYieldLF;
    QString RMilkVisit_AvgMilkTimePHourLR;
    QString RMilkVisit_AvgMilkTimePHourRR;
    QString RMilkVisit_AvgMilkTimePHourRF;
    QString RMilkVisit_AvgMilkTimePHourLF;
    QString RMilkVisit_FailedMilkTimeLR;
    QString RMilkVisit_FailedMilkTimeRR;
    QString RMilkVisit_FailedMilkTimeRF;
    QString RMilkVisit_FailedMilkTimeLF;
    QString RMilkVisit_MilkDestination;
    QString RMilkVisit_MilkDestReason;
    QString RMilkVisit_PreTreatmentTime;
    QString RMilkVisit_ConnectTime;
    QString RMilkVisit_PostTreatmentTime;
    QString RMilkVisit_MilkTime;
    QString RMilkVisit_CurrentNrMilkSamples;
    QString RMilkVisit_UdderScansNr;
    QString RMilkVisit_UdderScanTime;
    QString RMilkVisit_RearScansNr;
    QString RMilkVisit_FrontScansNr;
    QString RMilkVisit_RearScanTime;
    QString RMilkVisit_FrontScanTime;
    QString RMilkVisit_AttachmentTimeLR;
    QString RMilkVisit_AttachmentTimeRR;
    QString RMilkVisit_AttachmentTimeRF;
    QString RMilkVisit_AttachmentTimeLF;
    QString RMilkVisit_WaitTimeLelyWash;
    QString RMilkVisit_WaitTimeMilkJar;
    QString RMilkVisit_SCC_DrainTimeLR;
    QString RMilkVisit_SCC_DrainTimeRR;
    QString RMilkVisit_SCC_DrainTimeRF;
    QString RMilkVisit_SCC_DrainTimeLF;
    QString RMilkVisit_CurrentNrSCCSamples;
    QString RMilkVisit_Free1;
    QString RMilkVisit_LastMilkSamplingTime;


    //*********************************************

    QString RVisitTab_TagId;
    QString RVisitTab_StructId;
    QString RVisitTab_Result;
    QString RVisitTab_StartVisitTime;
    QString RVisitTab_EndVisitTime;
    QString RVisitTab_AnimalWeight;
    QString RVisitTab_AnimalActivity;
    QString RVisitTab_SeqNr;
    QString RVisitTab_ChangedSettings;
    QString RVisitTab_Free;
    QString RVisitTab_UserWaitTime;


    //*****************************************************


    QString RFeedSettings_TagId;
    QString RFeedSettings_StructId;
    QString RFeedSettings_FeedingSettings;
    QString RFeedSettings_CowId        ;
    QString RFeedSettings_CreationTime;
    QString RFeedSettings_FeedAlgorithm;
    QString RFeedSettings_NrOfFeedTypes;
    QString RFeedSettings_ConnectFailFactor;
    QString RFeedSettings_Free;
    QString RFeedSettings_FeedId1;
    QString RFeedSettings_DoseStratic1;
    QString RFeedSettings_BlockTimeStart1;
    QString RFeedSettings_BlockTimeDuration1;
    QString RFeedSettings_AmountProHour1;
    QString RFeedSettings_FeedSpeed1;
    QString RFeedSettings_MinPeriodAmount1;
    QString RFeedSettings_MaxCredit1;
    QString RFeedSettings_MaxPeriodAmount1;
    QString RFeedSettings_FeedId2;
    QString RFeedSettings_DoseStratic2;
    QString RFeedSettings_BlockTimeStart2;
    QString RFeedSettings_BlockTimeDuration2;
    QString RFeedSettings_AmountProHour2;
    QString RFeedSettings_FeedSpeed2;
    QString RFeedSettings_MinPeriodAmount2;
    QString RFeedSettings_MaxCredit2;
    QString RFeedSettings_MaxPeriodAmount2;
    QString RFeedSettings_FeedId13;
    QString RFeedSettings_DoseStratic3;
    QString RFeedSettings_BlockTimeStart3;
    QString RFeedSettings_BlockTimeDuration3;
    QString RFeedSettings_AmountProHour3;
    QString RFeedSettings_FeedSpeed3;
    QString RFeedSettings_MinPeriodAmount3;
    QString RFeedSettings_MaxCredit3;
    QString RFeedSettings_MaxPeriodAmount3;
    QString RFeedSettings_FeedId4;
    QString RFeedSettings_DoseStratic4;
    QString RFeedSettings_BlockTimeStart4;
    QString RFeedSettings_BlockTimeDuration4;
    QString RFeedSettings_AmountProHour4;
    QString RFeedSettings_FeedSpeed4;
    QString RFeedSettings_MinPeriodAmount4;
    QString RFeedSettings_MaxCredit4;
    QString RFeedSettings_MaxPeriodAmount4;
    QString RFeedSettings_FeedId5;
    QString RFeedSettings_DoseStratic5;
    QString RFeedSettings_BlockTimeStart5;
    QString RFeedSettings_BlockTimeDuration5;
    QString RFeedSettings_AmountProHour5;
    QString RFeedSettings_FeedSpeed5;
    QString RFeedSettings_MinPeriodAmount5;
    QString RFeedSettings_MaxCredit5;
    QString RFeedSettings_MaxPeriodAmount5;
    QString RFeedSettings_FeedId6;
    QString RFeedSettings_DoseStratic6;
    QString RFeedSettings_BlockTimeStart6;
    QString RFeedSettings_BlockTimeDuration6;
    QString RFeedSettings_AmountProHour6;
    QString RFeedSettings_FeedSpeed6;
    QString RFeedSettings_MinPeriodAmount6;
    QString RFeedSettings_MaxCredit6;
    QString RFeedSettings_MaxPeriodAmount6;
    QString RFeedSettings_FeedId7;
    QString RFeedSettings_DoseStratic7;
    QString RFeedSettings_BlockTimeStart7;
    QString RFeedSettings_BlockTimeDuration7;
    QString RFeedSettings_AmountProHour7;
    QString RFeedSettings_FeedSpeed7;
    QString RFeedSettings_MinPeriodAmount7;
    QString RFeedSettings_MaxCredit7;
    QString RFeedSettings_MaxPeriodAmount7;
    QString RFeedSettings_FeedId8;
    QString RFeedSettings_DoseStratic8;
    QString RFeedSettings_BlockTimeStart8;
    QString RFeedSettings_BlockTimeDuration8;
    QString RFeedSettings_AmountProHour8;
    QString RFeedSettings_FeedSpeed8;
    QString RFeedSettings_MinPeriodAmount8;
    QString RFeedSettings_MaxCredit8;
    QString RFeedSettings_MaxPeriodAmount8;
    QString RFeedSettings_FeedId9;
    QString RFeedSettings_DoseStratic9;
    QString RFeedSettings_BlockTimeStart9;
    QString RFeedSettings_BlockTimeDuration9;
    QString RFeedSettings_AmountProHour9;
    QString RFeedSettings_FeedSpeed9;
    QString RFeedSettings_MinPeriodAmount9;
    QString RFeedSettings_MaxCredit9;
    QString RFeedSettings_MaxPeriodAmount9;

    //********************************************


    QString RGWSettings_TagId;
    QString RGWSettings_StructId;
    QString RGWSettings_Free;
    QString RGWSettings_CreationTime;
    QString RGWSettings_MinMilkInt;
    QString RGWSettings_MinMilkIntGrazing;
    QString RGWSettings_CowSelectionSettings;
    QString RGWSettings_NrOfCowSeparations;
    QString RGWSettings_ManualDestPrio;
    QString RGWSettings_ManualDest;
    QString RGWSettings_ManualDestStartTime;
    QString RGWSettings_ManualDestDuration;
    QString RGWSettings_MilkNowPrio;
    QString RGWSettings_MilkNowDest;
    QString RGWSettings_MilkNowStartTime;
    QString RGWSettings_MilkNowDuration;
    QString RGWSettings_NearMilkPrio;
    QString RGWSettings_NearMilkDest;
    QString RGWSettings_NearMilkingStartTime;
    QString RGWSettings_NearMilkDuration;
    QString RGWSettings_MilkedPrio;
    QString RGWSettings_MilkedDest;
    QString RGWSettings_MilkedStartTime;
    QString RGWSettings_MilkedDuration;
    QString RGWSettings_FailedMilkPrio;
    QString RGWSettings_FailedMilkDest;
    QString RGWSettings_FailedMilkStartTime;
    QString RGWSettings_FailedMilkDuration;
    QString RGWSettings_NrFailedMilksPrio;
    QString RGWSettings_NrFailedMilksDest;
    QString RGWSettings_NrFailedMilkStartTime;
    QString RGWSettings_NrFailedMilkDuration;
    QString RGWSettings_GrazingAPrio;
    QString RGWSettings_GrazingADest;
    QString RGWSettings_GrazingAStartTime;
    QString RGWSettings_GrazingADuration;
    QString RGWSettings_GrazingBPrio;
    QString RGWSettings_GrazingBDest;
    QString RGWSettings_GrazingBStartTime;
    QString RGWSettings_GrazingBDuration;
    QString RGWSettings_GrazingCPrio;
    QString RGWSettings_GrazingCDest;
    QString RGWSettings_GrazingCStartTime;
    QString RGWSettings_GrazingCDuration;
    QString RGWSettings_GrazingDPrio;
    QString RGWSettings_GrazingDDest;
    QString RGWSettings_GrazingDStartTime;
    QString RGWSettings_GrazingDDuration;
    QString RGWSettings_Free_1;
    QString RGWSettings_Free_2;









};

#endif // DataSystems_H
