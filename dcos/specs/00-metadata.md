# 00 メタデータ — WinSelector 仕様書

## 文書情報

| 項目 | 内容 |
|---|---|
| 対象システム | WinSelector(Windows 11 タスクバー代替パネル) |
| 解析リビジョン | a59a66f(master) |
| 生成日 | 2026-06-28(フル再実行) |
| 文書種別 | コードからの逆生成仕様書(reverse specification) |
| 生成方式 | cc-rsg(Codebase Reverse Specification Generator) |
| 出力言語 | 日本語(ja) |
| 想定読者 | 新規メンバー(new_team_member) |
| 目的 | 保守(maintenance) |
| 詳細度 | comprehensive |
| 観点 | architecture, interfaces |
| テンプレート | gui-app(デスクトップ GUI) |
| 実行モード | sequential |

## ソース抽出方式(本ランの特記)

- **高精度抽出(libclang)を使用**。`compile_commands.json`
  (`build/Debug_Windows`)+ libclang 18.1.1 により、`source-map.py` は
  `cpp_extractor: clang` で **112 ユニット**を抽出(regex 時は 87)。
  劣化(`cpp_degraded_reason`)は null。
- これに合わせインベントリを関数粒度の **71 ユニット**へ細分化(前回ランの
  `inventory < 50` 例外を解消)。

## 対象範囲

- 対象: `src/` 配下の C++/Qt6 ソース、`CMakeLists.txt`、`CMakePresets.json`、
  `resources/`。
- 除外: `build/`、`.git/`、IDE 設定、エージェント関連ディレクトリ。

## 技術スタック概要

- 言語: C++17 [REF: CMakeLists.txt:9-10]。
- フレームワーク: Qt6 Widgets [REF: CMakeLists.txt:12-13]。
- OS: Windows 専用(Win32 API 直接利用、`user32/gdi32/psapi/shell32`)
  [REF: CMakeLists.txt:50-52]。
- ビルド: CMake(最小 3.16) [REF: CMakeLists.txt:1]。

## 章構成

| ID | ファイル | タイトル |
|---|---|---|
| CH-01 | 01-overview.md | 概要 |
| CH-02 | 02-architecture.md | アーキテクチャ概要 |
| CH-03 | 03-screens-interaction.md | 画面構成と操作 |
| CH-04 | 04-features.md | 機能と振る舞い |
| CH-05 | 05-win32-integration.md | Win32 API連携・イベント |
| CH-06 | 06-settings-persistence.md | 設定と永続化 |
| CH-07 | 07-build-distribution.md | ビルドと配布 |
| CH-08 | 08-constraints-unresolved.md | 既知の制約と未解決事項 |

## 凡例

- `[REF: path:line]` — 検証済みソース位置。
- `[CONFIDENCE: HIGH|MED|LOW]` — 主張の確からしさ。
- `[ASSUMED: ...; basis: ...]` — 明示的な推論。
- `[BLOCKED: see Q-NNN]` — 意図不明により保留(本書では Phase 5 で全件解消済み)。

## 既知の限界

- 全 8 章とも本文行数は cc-rsg の comprehensive 既定しきい値(200 行/章)を下回る。
  対象が小規模(全約 1,925 行)であり、水増しを避けた結果の正当な例外
  (`verification-report.md` に記録)。MECE は 100%(libclang 112 ユニット全カバー)。
- 未解決: Q-003(初期/更新後ジオメトリ基準領域の差)のみ abandoned。詳細は
  `99-unresolved.md`。

## Sources Read

- `CMakeLists.txt`
