// Task7.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "../GPlotTools/plot.h"
#include "../generateWaveHelper/generateWave.h"

constexpr auto fs = 8192;//サンプリング周波数(2のべき乗)

//[in]question_number = 問題番号,[in] fc = キャリア周波数
void printTask7Answer(const unsigned int question_number, const unsigned int fc)
{
   const auto graph_title = "waveform" + std::to_string(question_number) + "-";
   const auto graph_title_fft = "spectrum" + std::to_string(question_number) + "-";
   const auto file_name = "command" + std::to_string(question_number) + "-";
   const auto file_name_fft = "command_fft" + std::to_string(question_number) + "-";

   //情報信号
   GenerateWave graph1(fs, 0.5);
   graph1.generateTriangle(0.15, 1.5);
   graph1.generateSquare(0.05, 0.0);
   graph1.moveAmplitude(0.075);
   Plot(graph1.getGraph().x, graph1.getGraph().y, "t[sec]", "Amplitude", "Waveform", graph_title + "1.plt", file_name + "1.bat").executionPlot();
   Plot(graph1.applyFft().x, graph1.applyFft().y, "f[Hz]", "Amplitude", "Apply FFT", graph_title_fft + "1.plt", file_name_fft + "1.bat").executionPlotAbs();

   //搬送波
   GenerateWave graph2(fs, 0.5);
   graph2.generateCarrierWave(fc, 1.0);
   Plot(graph2.getGraph().x, graph2.getGraph().y, "t[sec]", "Amplitude", "Waveform", graph_title + "2.plt", file_name + "2.bat").executionPlot();
   Plot(graph2.applyFft().x, graph2.applyFft().y, "f[Hz]", "Amplitude", "Apply FFT", graph_title_fft + "2.plt", file_name_fft + "2.bat").executionPlotAbs();

   //DSB変調波
   auto graph3 = graph1 * graph2;
   Plot(graph3.getGraph().x, graph3.getGraph().y, "t[sec]", "Amplitude", "Waveform", graph_title + "3.plt", file_name + "3.bat").executionPlot();
   Plot(graph3.applyFft().x, graph3.applyFft().y, "f[Hz]", "Amplitude", "Apply FFT", graph_title_fft + "3.plt", file_name_fft + "3.bat").executionPlotAbs();
   return;
}

int main()
{
   printTask7Answer(1, 250);
   return 0;
}
