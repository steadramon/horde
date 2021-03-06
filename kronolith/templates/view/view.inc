<div class="horde-form">
<table>

<?php if (!$private): ?>
<!-- location -->
<tr>
 <td class="rightAlign"><strong><?php echo _("Location") ?></strong></td>
 <td><?php echo empty($location) ? '&nbsp;' : $GLOBALS['injector']->getInstance('Horde_Core_Factory_TextFilter')->filter($location, 'text2html', array('parselevel' => Horde_Text_Filter_Text2html::MICRO, 'class' => 'text')) ?> </td>
</tr>
<?php endif; ?>

<?php if (!$private && strlen($eventurl)): ?>
<!-- url -->
<tr>
 <td class="rightAlign"><strong><?php echo _("URL") ?></strong></td>
 <td><?php echo $GLOBALS['injector']->getInstance('Horde_Core_Factory_TextFilter')->filter($eventurl, 'linkurls') ?></td>
</tr>
<?php endif; ?>

<!-- status -->
<tr>
 <td width="10%" class="rightAlign"><strong><?php echo _("Status") ?></strong></td>
 <td width="90%"><?php echo empty($status) ? '&nbsp;' : htmlspecialchars($status) ?> </td>
</tr>

<?php if (!empty($owner)): ?>
<!-- owner -->
<tr>
 <td class="rightAlign"><strong><?php echo _("Owner") ?></strong></td>
 <td><?php echo htmlspecialchars($owner) ?> </td>
</tr>
<?php endif; ?>

<!-- start date -->
<tr>
 <td class="rightAlign"><strong><?php echo _("Start On") ?></strong></td>
 <td><?php echo $this->event->start->strftime($dateFormat) . ' '; echo $this->event->isAllDay() ? _("All day event") : $this->event->start->format($timeFormat) ?></td>
</tr>

<?php if (!$this->event->isAllDay()): ?>
<!-- end date -->
<tr>
 <td class="rightAlign"><strong><?php echo _("End On") ?></strong></td>
 <td><?php echo $this->event->end->strftime($dateFormat) . ' ' . $this->event->end->format($timeFormat) ?></td>
</tr>
<?php endif; ?>

<!-- alarm -->
<tr>
 <td class="rightAlign"><strong><?php echo _("Alarm") ?></strong></td>
 <td>
<?php
if ($this->event->initialized && $this->event->alarm > 0):
    if ($this->event->alarm % 10080 == 0) {
        $alarm_value = $this->event->alarm / 10080;
        $alarm_unit = _("Week(s)");
    } elseif ($this->event->alarm % 1440 == 0) {
        $alarm_value = $this->event->alarm / 1440;
        $alarm_unit = _("Day(s)");
    } elseif ($this->event->alarm % 60 == 0) {
        $alarm_value = $this->event->alarm / 60;
        $alarm_unit = _("Hour(s)");
    } else {
        $alarm_value = $this->event->alarm;
        $alarm_unit = _("Minute(s)");
    }
?>
  <?php echo $alarm_value . ' ' . $alarm_unit ?>
<?php else: ?>
  <?php echo _("No alarm") ?>
<?php endif; ?>
 </td>
</tr>

<?php if ($this->event->created): ?>
<tr>
  <td class="nowrap rightAlign"><strong><?php echo _("Created") ?></strong></td>
  <td class="nowrap"><?php  echo $this->event->created->strftime($dateFormat) . ' ' . $this->event->created->format($timeFormat) . ' ' . htmlspecialchars($this->event->createdby) ?></td>
</tr>
<?php endif; ?>

<?php if ($this->event->modified): ?>
<tr>
  <td class="nowrap rightAlign"><strong><?php echo _("Last Modified") ?></strong></td>
  <td class="nowrap"><?php echo $this->event->modified->strftime($dateFormat) . ' ' . $this->event->modified->format($timeFormat) . ' ' . htmlspecialchars($this->event->modifiedby) ?></td>
</tr>
<?php endif; ?>


<?php if ($this->event->recurs() || !empty($this->event->baseid)): ?>
<!-- recurrence -->
<tr>
 <td colspan="2" class="control"><strong><?php echo _("Recurrence") ?></strong></td>
</tr>
<tr>
 <td class="rightAlign" valign="top"><strong><?php echo _("Pattern") ?></strong></td>
 <td valign="top">
<?php if ($this->event->baseid):?>
   <?php echo sprintf(_("This is an exception to a recurring event originally scheduled on %s at %s"), $this->event->exceptionoriginaldate->strftime($GLOBALS['prefs']->getValue('date_format')), $this->event->exceptionoriginaldate->strftime(($GLOBALS['prefs']->getValue('twentyFour') ? '%H:%M' : '%I:%M %p')));?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_DAILY)): ?>
   <?php echo _("Daily: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("day(s)") ?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_WEEKLY)):
    $weekdays = array();
    if ($this->event->recurrence->recurOnDay(Horde_Date::MASK_MONDAY))    $weekdays[] = _("Monday");
    if ($this->event->recurrence->recurOnDay(Horde_Date::MASK_TUESDAY))   $weekdays[] = _("Tuesday");
    if ($this->event->recurrence->recurOnDay(Horde_Date::MASK_WEDNESDAY)) $weekdays[] = _("Wednesday");
    if ($this->event->recurrence->recurOnDay(Horde_Date::MASK_THURSDAY))  $weekdays[] = _("Thursday");
    if ($this->event->recurrence->recurOnDay(Horde_Date::MASK_FRIDAY))    $weekdays[] = _("Friday");
    if ($this->event->recurrence->recurOnDay(Horde_Date::MASK_SATURDAY))  $weekdays[] = _("Saturday");
    if ($this->event->recurrence->recurOnDay(Horde_Date::MASK_SUNDAY))    $weekdays[] = _("Sunday");
    echo _("Weekly: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("week(s) on:") . ' ' . implode(', ', $weekdays) ?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_MONTHLY_DATE)): ?>
   <?php echo _("Monthly: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("month(s)") . ' ' . _("on the same date") ?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_MONTHLY_WEEKDAY)): ?>
   <?php echo _("Monthly: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("month(s)") . ' ' . _("on the same weekday") ?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_MONTHLY_LAST_WEEKDAY)): ?>
   <?php echo _("Monthly: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("month(s)") . ' ' . _("on the same last weekday") ?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_YEARLY_DATE)): ?>
   <?php echo _("Yearly: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("year(s) on the same date") ?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_YEARLY_DAY)): ?>
   <?php echo _("Yearly: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("year(s) on the same day of the year") ?>
<?php elseif ($this->event->recurrence->hasRecurType(Horde_Date_Recurrence::RECUR_YEARLY_WEEKDAY)): ?>
   <?php echo _("Yearly: Recurs every") . ' ' . $this->event->recurrence->getRecurInterval() . ' ' . _("year(s) on the same weekday and month of the year") ?>
<?php endif; ?>
 </td>
</tr>

<!-- recur end date -->
<?php if ($this->event->recurs()): ?>
<tr>
 <td class="rightAlign"><strong><?php echo _("Recur Until") ?></strong></td>
 <td><?php echo $this->event->recurrence->hasRecurEnd() ? $this->event->recurrence->recurEnd->strftime($dateFormat) . ($this->event->recurrence->recurEnd->hour == 23 && $this->event->recurrence->recurEnd->min == 59 ? '' : ' ' . $this->event->recurrence->recurEnd->format($timeFormat)) : ($this->event->recurrence->getRecurCount() ? sprintf(_("%d times"), $this->event->recurrence->getRecurCount()) : _("No end date")) ?></td>
</tr>

<?php if ($this->event->recurrence->getExceptions()): ?>
<!-- exceptions -->
<tr>
 <td class="rightAlign"><strong><?php echo _("Exceptions") ?></strong></td>
 <td><?php echo $this->event->exceptionsList(); ?></td>
</tr>
<?php endif; endif; endif; ?>

<?php if (!$private): ?>
<!-- tags  -->
<?php if (!empty($tags)):?>
    <tr>
     <td colspan="2" class="control"><strong><?php echo _("Tags")?></strong></td>
    </tr>
    <tr>
     <td colspan="2"><?php echo htmlspecialchars($tags)?></td>
    </tr>
<?php endif;?>

<?php if (!empty($description)): ?>
<!-- description -->
<tr>
 <td colspan="2" class="control"><strong><?php echo _("Description") ?></strong></td>
</tr>
<tr>
 <td colspan="2" class="description"><?php echo $GLOBALS['injector']->getInstance('Horde_Core_Factory_TextFilter')->filter($description, 'text2html', array('parselevel' => Horde_Text_Filter_Text2html::MICRO, 'class' => 'text')) ?></td>
</tr>
<?php endif; ?>
<?php endif; ?>

</table>
</div>

<?php if (!$private): ?>
<div class="horde-content">
<table>
<?php if (count($attendees)): ?>
 <!-- attendees -->
 <tr class="leftAlign">
  <th><?php echo _("Attendee") ?></th>
  <th><?php echo _("Attendance") ?></th>
  <th><?php echo _("Response") ?></th>
 </tr>
<?php $link_emails = $GLOBALS['registry']->hasMethod('mail/compose'); foreach ($attendees as $attendee): ?>
 <tr>
  <td class="nowrap"><?php echo ($link_emails && $attendee->addressObject->host) ? ($GLOBALS['registry']->call('mail/compose', array(array('to' => $attendee->addressObject)))->link(array('title' => sprintf(_("Send an email to %s"), $attendee->displayName))) . htmlspecialchars($attendee->addressObject) . '</a>') : htmlspecialchars($attendee) ?></td>
  <td><?php echo Kronolith::partToString($attendee->role) ?></td>
  <td><?php echo Kronolith::responseToString($attendee->response) ?></td>
 </tr>
<?php endforeach; ?>
<?php endif; ?>
 <!-- resources -->
<?php if (!empty($resources)): ?>
 <tr class="leftAlign">
  <th><?php echo _("Resource") ?></th>
  <th><?php echo _("Attendance") ?></th>
  <th><?php echo _("Response") ?></th>
 </tr>
<?php foreach ($resources as $id => $resource):?>
 <tr>
  <td class="nowrap"><?php echo htmlspecialchars($resource['name'])?></td>
  <td><?php echo Kronolith::partToString($resource['attendance']) ?></td>
  <td><?php echo Kronolith::responseToString($resource['response']) ?></td>
 </tr>
<?php endforeach;?>
<?php endif; ?>
</table>
</div>
<?php endif; ?>
