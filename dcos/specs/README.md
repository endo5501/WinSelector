# WinSelector 仕様書(コードからの逆生成 / フル再実行)

本書は WinSelector のソースコード(解析リビジョン **a59a66f** / master)から
cc-rsg により逆生成した保守向け仕様書です。想定読者は新規メンバー、目的は保守、
詳細度は comprehensive、観点はアーキテクチャとインターフェースです。

> 本ランは **libclang 18.1.1 による高精度(clang)抽出**を使用しています
> (`compile_commands.json` = `build/Debug_Windows`)。`source-map.py` は
> 112 ユニットを抽出し、インベントリは関数粒度の 71 件です。

## 読み方ガイド

| 順 | ファイル | 内容 | こんなときに |
|---|---|---|---|
| 0 | [00-metadata.md](00-metadata.md) | 文書情報・抽出方式・既知の限界 | 本書の前提を知る |
| 1 | [01-overview.md](01-overview.md) | 目的・主要ユースケース・全体図 | まず 3 分で全体像 |
| 2 | [02-architecture.md](02-architecture.md) | レイヤ構成・依存・ディレクトリ | 設計方針を把握 |
| 3 | [03-screens-interaction.md](03-screens-interaction.md) | オーバーレイ/タイル/レイアウト | UI まわりを直す |
| 4 | [04-features.md](04-features.md) | 走査・更新・操作の振る舞い | 機能の流れを追う |
| 5 | [05-win32-integration.md](05-win32-integration.md) | Win32 API 連携・ホットキー・トレイ | OS 連携を直す |
| 6 | [06-settings-persistence.md](06-settings-persistence.md) | Settings.ini・設定アクセサ・i18n | 設定項目を扱う |
| 7 | [07-build-distribution.md](07-build-distribution.md) | CMake・プリセット・windeployqt | ビルド/配布を行う |
| 8 | [08-constraints-unresolved.md](08-constraints-unresolved.md) | 制約・乖離・確定した設計判断 | 落とし穴を避ける |
| — | [99-unresolved.md](99-unresolved.md) | 未解決(Q-003)と解決済み一覧 | 残課題を確認 |
| — | [traceability.md](traceability.md) | 章→ソースの対応(MECE 100%) | 根拠ソースを辿る |

## 品質サマリ

- トレーサビリティ: libclang 抽出 **112 ユニットを 100% カバー**(MECE PASS)。
- インベントリ: **71 ユニット**(関数粒度)。
- 全主張に `[REF: path:line]`、確からしさは `[CONFIDENCE: ...]` で明示。
- 未解決: Q-003 のみ abandoned。他 5 件は解決済み。
- 既知の限界(本文行数しきい値)は小規模コードベースゆえの正当な例外として
  `00-metadata.md` / `../verification-report.md` に記録。

## 注意

- 本書はリビジョン a59a66f 時点の事実を反映します。
- CLAUDE.md の一部記述(タイル全再生成・幅 300px 固定)は現行実装と乖離して
  います。詳細は `08-constraints-unresolved.md` を参照してください。
