# 99 未解決事項

本章は Question Bank(`.cc-rsg/questions.json`)の最終状態を集約する。Phase 5
の対話により、6 件中 5 件が解決(answered)、1 件が保留により放棄(abandoned)
となった。

## オープンな質問

- なし(open: 0 件)。

## 放棄(abandoned)項目

### Q-003 [nice-to-have / architecture_decision / status: abandoned]

- 内容: `setupUi` は `screen->geometry()`、`adjustWindowGeometry` は
  `availableGeometry()` を用い、初期配置と更新後配置でタスクバー領域の扱いが
  異なる。この差異が意図的か [REF: src/mainwindow.cpp:70-82]
  [REF: src/mainwindow.cpp:174-175]。
- 放棄理由: 現時点で設計意図を確定できず、ユーザ判断も保留。
- 現状の推論: 初期は全画面高で仮置きし、更新時に作業領域へ収める挙動と推測
  [CONFIDENCE: LOW]。動作上の実害は確認されていない。
- 将来の解決に必要なもの: 設計者への確認、または初期/更新ロジックの統一可否の
  検討。

## 解決済みの質問(参考)

| ID | severity | 結論 |
|---|---|---|
| Q-001 | important | 「閉じる」は WM_CLOSE のみが確定仕様(プロセス終了は要件外)。 |
| Q-002 | nice-to-have | 自動テスト未整備、現状は手動検証中心。 |
| Q-004 | nice-to-have | 対象 Qt は Qt6 で確定。 |
| Q-005 | nice-to-have | windeployqt の除外は確定要件。 |
| Q-006 | nice-to-have | アイコンキャッシュのクリアは単なる更新目的(陳腐化対策ではない)。 |

## メモ

- 解決済みの詳細は各章および `08-constraints-unresolved.md` に反映済み。
