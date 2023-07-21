//
// Created by xtx on 2022/11/18.
//

#ifndef MAIN_COMPONENTS_DATACIRCULATION_DATACIRCULATION_H_
#define MAIN_COMPONENTS_DATACIRCULATION_DATACIRCULATION_H_

#include "RepeaterWidget.h"
#include "Charts/charts_next.h"
#include "mainwindow.h"
#include "dataengineinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DataCirculation; }
QT_END_NAMESPACE
class DataCirculation : public RepeaterWidget {
 Q_OBJECT

public:
    explicit DataCirculation(int device_num, int win_num, QSettings *cfg, ToNewWidget *parent_info,
                             QWidget *parent = nullptr);

    ~DataCirculation() override;

    enum CirculationMode {
        CIRCULATION_MODE_DIRECTION = 0,
        CIRCULATION_MODE_COMMA_SEPARATED,
        CIRCULATION_MODE_KEY_VALUE,
        CIRCULATION_MODE_JUST_FLOAT,
        CIRCULATION_MODE_SCANF,
        CIRCULATION_MODE_REGULARITY,
        CIRCULATION_MODE_PYTHON,
    } circulation_mode_ = CIRCULATION_MODE_DIRECTION;
    enum ProcessMode {
      PROCESS_MODE_NONE = 0,
      PROCESS_MODE_CIRCULATION,
      PROCESS_MODE_OUTPUT,
    } process_mode_ = PROCESS_MODE_NONE;
    enum DateFlowMode {
      DATE_FLOW_MODE_CHART = 0,
      DATE_FLOW_MODE_OUTPUT,
    } date_flow_mode_ = DATE_FLOW_MODE_CHART;
    enum OutputMode {
        OUTPUT_MODE_TCP_SERVER = 0,
        OUTPUT_MODE_POST,
    } output_mode_ = OUTPUT_MODE_TCP_SERVER;

    TimeType time_type_=DATA_TIME;

    void GetConstructConfig() override;

    void SaveConstructConfig() override;

    void RefreshBox();

 private:
    Ui::DataCirculation *ui_;

    void TestCirculationMode();

    void StartCirculation();

    void StopCirculation();

    void DoCirculation(const QByteArray &data, const QDateTime &data_time = QDateTime::currentDateTime());

    void GetData(const QString &point_name,double data,const QDateTime &time);

    ChartsNext *chart_window_;

    struct value {
        QString name;
        QString rule;
    };

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                std::list<value> values_;

    void JustFloat(const QString &str, const QDateTime &data_time);

    int image_count_mutation_count_ = 0;

    int data_time_now_=0;
};

#endif //MAIN_COMPONENTS_DATACIRCULATION_DATACIRCULATION_H_
