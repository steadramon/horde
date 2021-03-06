<div class="prefsSmimeContainer">
 <div class="prefsSmimeHeader">
  <h3>
   <?php echo _("Your S/MIME Personal Certificate") ?>
   <?php echo $this->hordeHelp('imp', 'smime-overview-personalkey') ?>
  </h3>
 </div>

<?php if ($this->notsecure): ?>
 <div>
  <em class="prefsSmimeWarning"><?php echo _("S/MIME Personal Certificate support requires a secure web connection.") ?></em>
 </div>
<?php elseif ($this->has_key): ?>
<?php if ($this->expiredate): ?>
 <p class="prefsSmimeWarning"><?php printf(_("Your S/MIME Personal Certificate has expired on %s at %s."), $this->expiredate, $this->expiretime) ?></p>
<?php endif ?>
 <div>
  <table>
   <tr>
    <td>
     <?php echo _("Your Public Certificate") ?>:
    </td>
    <td>
     [<?php echo $this->viewpublic ?>]
     [<?php echo $this->infopublic ?>]
    </td>
   </tr>
   <tr>
    <td>
     <?php echo _("Your Private Certificate") ?>:
    </td>
    <td>
     [<?php echo $this->passphrase ?>]
     [<?php echo $this->viewprivate ?>]
    </td>
   </tr>
  </table>
 </div>

 <p>
  <input type="submit" id="delete_smime_personal" name="delete_smime_personal" class="horde-delete" value="<?php echo _("Delete Personal Certificate") ?>" />
  <?php echo $this->hordeHelp('imp', 'smime-delete-personal-certs') ?>
 </p>
<?php if ($this->has_sign_key): ?>
 <div class="prefsSmimeHeader">
  <h3>
   <?php echo _("Your Secondary S/MIME Personal Certificate") ?>
  </h3>
 </div>

<?php if ($this->expiredate_sign): ?>
 <p class="prefsSmimeWarning"><?php printf(_("Your Secondary S/MIME Personal Certificate has expired on %s at %s."), $this->expiredate_sign, $this->expiretime_sign) ?></p>
<?php endif ?>
 <div>
  <table>
   <tr>
    <td>
     <?php echo _("Your Secondary Public Certificate") ?>:
    </td>
    <td>
     [<?php echo $this->viewpublic_sign ?>]
     [<?php echo $this->infopublic_sign ?>]
    </td>
   </tr>
   <tr>
    <td>
     <?php echo _("Your Secondary Private Certificate") ?>:
    </td>
    <td>
     [<?php echo $this->passphrase_sign ?>]
     [<?php echo $this->viewprivate_sign ?>]
    </td>
   </tr>
  </table>
 </div>

 <p>
  <input type="submit" id="delete_smime_personal_sign" name="delete_smime_personal_sign" class="horde-delete" value="<?php echo _("Delete Secondary Personal Certificate") ?>" />
  <?php echo $this->hordeHelp('imp', 'smime-delete-personal-certs') ?>
 </p>
<?php endif ?>
<?php else: ?>
 <div>
  <em><?php echo _("No personal certificate") ?></em>
 </div>
<?php endif ?>
<?php if ($this->import): ?>
 <div>
  <p>
   <input type="submit" name="save" class="horde-default" id="import_smime_personal" value="<?php echo _("Import Personal Certificate") ?>" />
   <?php echo $this->hordeHelp('imp', 'smime-import-personal-certs') ?>
  </p>
 </div>
<?php endif; ?>
</div>
